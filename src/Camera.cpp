#include "Camera.h"
#include "InputManager.h"

Vec2 Camera::pos = {0, 0};
Vec2 Camera::speed = {0, 0};
GameObject* Camera::focus = nullptr;
void Camera::Follow(GameObject* newFocus){
    focus = newFocus;
}

void Camera::Unfollow(){
    focus = nullptr;
}

void Camera::Update(float dt){
    Vec2 a;
    if(InputManager::GetInstance().KeyPress(LEFT_ARROW_KEY)){
        Vec2 a = {-1, 0};
    } else if (InputManager::GetInstance().KeyPress(RIGHT_ARROW_KEY)){
        Vec2 a = {1, 0};
    } else if (InputManager::GetInstance().KeyPress(UP_ARROW_KEY)){
        Vec2 a = {0, -1};
    } else if (InputManager::GetInstance().KeyPress(DOWN_ARROW_KEY)){
        Vec2 a = {0, 1};
    } else {
        Vec2 a = {0, 0};
    }

    speed = speed + a*dt;
    pos = pos + speed;
}