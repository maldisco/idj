#include "Camera.h"
#include "InputManager.h"
#include <iostream>

Vec2 Camera::pos = Vec2(0, 0);
Vec2 Camera::speed = Vec2(100, 100);
GameObject* Camera::focus = nullptr;
void Camera::Follow(GameObject* newFocus){
    focus = newFocus;
}

void Camera::Unfollow(){
    focus = nullptr;
}

void Camera::Update(float dt){
    if(InputManager::GetInstance().IsKeyDown(LEFT_ARROW_KEY)){
        pos.x -= speed.x*dt;
    } 
    if (InputManager::GetInstance().IsKeyDown(RIGHT_ARROW_KEY)){
        pos.x += speed.x*dt;
    } 
    if (InputManager::GetInstance().IsKeyDown(UP_ARROW_KEY)){
        pos.y -= speed.y*dt;
    } 
    if (InputManager::GetInstance().IsKeyDown(DOWN_ARROW_KEY)){
        pos.y += speed.y*dt;
    }   
}