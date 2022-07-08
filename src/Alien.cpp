#include "Alien.h"
#include "Sprite.h"
#include "InputManager.h"
#include "Camera.h"
#include <iostream>


Alien::Alien(GameObject& associated, int nMinions) : Component(associated), speed({100, 100}), hp(100){
    associated.AddComponent(new Sprite("assets/img/alien.png", associated));
}

Alien::~Alien(){
    minionArray.clear();
}

void Alien::Start(){

}

void Alien::Update(float dt){
    if(InputManager::GetInstance().MousePress(LEFT_MOUSE_BUTTON)){
        taskQueue.emplace( Action(Action::ActionType::SHOOT,
         InputManager::GetInstance().GetMouseX()+Camera::pos.x,
         InputManager::GetInstance().GetMouseY()+Camera::pos.y) );
    }

    if(InputManager::GetInstance().MousePress(RIGHT_MOUSE_BUTTON)){
        // add a move action to queue
        // to mouse direction
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
            float angle = SDL_atan2(dir.y, dir.x) - SDL_atan2(speed.y, speed.x);
            Vec2 newSpeed = speed.Rotate(angle);
            

            //speed = speed.Rotate(Vec2::Slope(speed, taskQueue.front().pos - associated.box.Center()));
            std::cout << "speed : (" << speed.x << ", " << speed.y << ") " << std::endl;
            // if distance to click position is less than speed
            if(Vec2::Distance(associated.box.Center(), taskQueue.front().pos) < (speed*dt).Magnitude()){
                // go to click position
                associated.box.x = taskQueue.front().pos.x;
                associated.box.y = taskQueue.front().pos.y;
                taskQueue.pop();
            } else {
                // move in direction to the click
                associated.box.x += newSpeed.x*dt;
                associated.box.y += newSpeed.y*dt;
            }
            std::cout << "Alien se move para (" << associated.box.x << ", " << associated.box.y << ")" << std::endl;
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