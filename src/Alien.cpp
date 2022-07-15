#include "Alien.h"
#include "Minion.h"
#include "Sprite.h"
#include "Collider.h"
#include "InputManager.h"
#include "Camera.h"
#include "Game.h"
#include "Bullet.h"


Alien::Alien(GameObject& associated) : Component(associated), speed({100, 100}), hp(100){
    associated.AddComponent(new Sprite("assets/img/alien.png", associated, 1, 1.0));
    associated.AddComponent(new Collider(associated));
}

Alien::~Alien(){
    minionArray.clear();
}

void Alien::Start(){
    GameObject* minion = new GameObject();
    minion->AddComponent(new Minion(*minion, Game::GetInstance().GetState().GetObjectPtr(&associated)));
    minionArray.push_back(Game::GetInstance().GetState().AddObject(minion));

    GameObject* minion2 = new GameObject();
    minion2->AddComponent(new Minion(*minion2, Game::GetInstance().GetState().GetObjectPtr(&associated), PI/2));
    minionArray.push_back(Game::GetInstance().GetState().AddObject(minion2));

    GameObject* minion3 = new GameObject();
    minion3->AddComponent(new Minion(*minion3, Game::GetInstance().GetState().GetObjectPtr(&associated), PI));
    minionArray.push_back(Game::GetInstance().GetState().AddObject(minion3));

    GameObject* minion4 = new GameObject();
    minion4->AddComponent(new Minion(*minion4, Game::GetInstance().GetState().GetObjectPtr(&associated), 3*PI/2));
    minionArray.push_back(Game::GetInstance().GetState().AddObject(minion4));      
}

void Alien::Update(float dt){
    if(InputManager::GetInstance().MousePress(LEFT_MOUSE_BUTTON)){
        // Shoot in mouse click dir
        taskQueue.emplace( Action(Action::ActionType::SHOOT,
         InputManager::GetInstance().GetMouseX()+Camera::pos.x,
         InputManager::GetInstance().GetMouseY()+Camera::pos.y) );
    }

    if(InputManager::GetInstance().MousePress(RIGHT_MOUSE_BUTTON)){
        // Move to mouse click
        taskQueue.emplace( Action(Action::ActionType::MOVE,
         InputManager::GetInstance().GetMouseX()+Camera::pos.x,
         InputManager::GetInstance().GetMouseY()+Camera::pos.y));        
    }

    // if there is a task in queue
    if(!taskQueue.empty()){
        // if task is MOVE
        if(taskQueue.front().type == Action::ActionType::MOVE){
            // turn speed vector in mouse click direction
            Vec2 dir = taskQueue.front().pos -  associated.box.Center();
            Vec2 newSpeed = Vec2::Rotate(speed, Vec2::Slope(dir, speed));

            // if distance to click position is less than speed
            if(Vec2::Distance(associated.box.Center(), taskQueue.front().pos) < Vec2::Magnitude(speed*dt)){
                // go to click position
                associated.box.Centered(taskQueue.front().pos);
                taskQueue.pop();
            } else {
                // move in direction to the click
                associated.box.x += newSpeed.x*dt;
                associated.box.y += newSpeed.y*dt;
            }
        // if task is SHOOT
        } else {
            // search for minion closer to mouse click
            int closerDistance = INT_MAX;
            std::weak_ptr<GameObject> closerMinion;
            for(auto shootingMinion : minionArray){
                float distance = Vec2::Distance(shootingMinion.lock()->box.Center(), taskQueue.front().pos);
                if(distance < closerDistance){
                    closerDistance = distance;
                    closerMinion = shootingMinion;
                }
            }
            Minion* minion = static_cast<Minion*>(closerMinion.lock()->GetComponent("Minion"));
            minion->Shoot(taskQueue.front().pos);
            taskQueue.pop();
        }
    }

    // rotate alien sprite
    associated.angleDeg -= (ARC/2)*180/PI;
}

void Alien::NotifyCollision(GameObject& other){
    if(other.GetComponent("Bullet") != nullptr){
        Bullet* bullet = (Bullet*)other.GetComponent("Bullet");
        if(not bullet->targetsPlayer){
            this->hp -= 5;
            if(this->hp <= 0){
                associated.RequestDelete();
            }
        }
    }
}

void Alien::Render(){}

bool Alien::Is(std::string type){
    if(type.compare("Alien") == 0){
        return true;
    }

    return false;
}