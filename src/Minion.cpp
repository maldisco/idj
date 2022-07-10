#include "Minion.h"
#include "iostream"

Minion::Minion(GameObject& associated, std::weak_ptr<GameObject> alienCenter, float arcOffsetDeg) : Component(associated), alienCenter(alienCenter), arc(arcOffsetDeg){
    associated.AddComponent(new Sprite("assets/img/minion.png", associated));

    Vec2 origin = Vec2(100, 0).Rotate(arc) + alienCenter.lock().get()->box.Center();
    associated.box.x = origin.x - associated.box.w/2;
    associated.box.y = origin.y - associated.box.h/2;
}

void Minion::Update(float dt){
    if(alienCenter.expired()){
        return;
    }
    // increase arc
    arc += ARC;

    Vec2 origin = Vec2(100, 0).Rotate(arc) + alienCenter.lock().get()->box.Center();
    associated.box.x = origin.x - associated.box.w/2;
    associated.box.y = origin.y - associated.box.h/2;
}

void Minion::Render(){}

bool Minion::Is(std::string type){
    if(type.compare("Minion") == 0){
        return true;
    }

    return false;
}
