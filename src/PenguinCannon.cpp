#include "PenguinCannon.h"
#include "Sprite.h"
#include "InputManager.h"
#include "Bullet.h"
#include "Game.h"
#include "Camera.h"

PenguinCannon::PenguinCannon(GameObject& associated, std::weak_ptr<GameObject> penguinBody) : Component(associated), pbody(penguinBody), angle(0){
    associated.AddComponent(new Sprite("assets/img/cubngun.png", associated));
}

void PenguinCannon::Update(float dt){
    if(pbody.lock()->IsDead()){
        associated.RequestDelete();
    }

    associated.box.Centered(pbody.lock()->box.Center());

    Vec2 mouseCoord = {InputManager::GetInstance().GetMouseX()+Camera::pos.x, InputManager::GetInstance().GetMouseY()+Camera::pos.y};
    Vec2 direction = mouseCoord - associated.box.Center();
    associated.angleDeg = direction.SlopeX()*180/PI;

    if(InputManager::GetInstance().MousePress(LEFT_MOUSE_BUTTON)){
        Shoot();
    }
}

void PenguinCannon::Shoot(){
    GameObject* bulletObject = new GameObject();
    // Bullet(associated, angle, speed, damage, maxDistance, sprite, frameTime, frameCount)
    bulletObject->AddComponent(new Bullet(*bulletObject, associated.angleDeg*PI/180, 500, 10, 500, "assets/img/minionbullet2.png", 0.05, 3));

    // calculating bullet starting point
    Vec2 offset = (Vec2(associated.box.x+associated.box.w, associated.box.y+associated.box.h/2) - associated.box.Center()).Rotate(associated.angleDeg*PI/180);
    Vec2 start =  associated.box.Center() + offset;

    bulletObject->box.x = start.x - bulletObject->box.w/6; // divided by 6 cause bullet is composed by 3 equal-sized frames, so its width of 1 frame divided by 2
    bulletObject->box.y = start.y;
    bulletObject->angleDeg = associated.angleDeg;
    Game::GetInstance().GetState().AddObject(bulletObject);
}

void PenguinCannon::Render(){}

bool PenguinCannon::Is(std::string type){
    if(type.compare("Penguin cannon") == 0){
        return true;
    }

    return false;
}