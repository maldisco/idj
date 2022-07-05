#include "Alien.h"
#include "Sprite.h"
#include "InputManager.h"
#include "Camera.h"

Alien::Alien(GameObject& associated, int nMinions) : Component(associated), speed({}), hp(0){
    associated.AddComponent(new Sprite(associated));
}

Alien::~Alien(){
    minionArray.clear();
}

void Alien::Start(){

}

void Alien::Update(float dt){
    if(InputManager::GetInstance().MousePress(LEFT_MOUSE_BUTTON)){
        taskQueue.emplace(new Action(Action::ActionType::SHOOT,
         InputManager::GetInstance().GetMouseX()+Camera::pos.x,
         InputManager::GetInstance().GetMouseX()+Camera::pos.y) );
    }

    if(InputManager::GetInstance().MousePress(RIGHT_MOUSE_BUTTON)){
        taskQueue.emplace(new Action(Action::ActionType::MOVE,
         InputManager::GetInstance().GetMouseX()+Camera::pos.x,
         InputManager::GetInstance().GetMouseX()+Camera::pos.y));
    }

    if(!taskQueue.empty()){
        if(taskQueue.front().type == Action::ActionType::MOVE){
            speed.Rotate(Vec2::Slope(speed, taskQueue.front().pos));
            if(Vec2::Distance(associated.box.Center(), taskQueue.front().pos) < speed.Magnitude()){
                associated.box.x = taskQueue.front().pos.x;
                associated.box.y = taskQueue.front().pos.y;
                taskQueue.pop();
            } else {
                associated.box = (associated.box + speed);
            }
        } else {
            taskQueue.pop();
        }
    }

    if(hp <= 0){
        associated.RequestDelete();
    }
}

void Alien::Render(){}

bool Alien::Is(std::string type){
    if(type.compare("Alien") == 0){
        return true;
    }

    return false;
}