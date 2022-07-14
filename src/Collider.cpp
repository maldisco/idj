#include "Collider.h"

Collider::Collider(GameObject& associated, Vec2 scale, Vec2 offset) : Component(associated), scale(scale), offset(offset) {

}

void Collider::Update(float dt){
    this->box.x = associated.box.x;
    this->box.y = associated.box.y;
    this->box.w = associated.box.w;
    this->box.h = associated.box.h;


    this->box.w = this->box.w*scale.x;
    this->box.h = this->box.h*scale.y;
    this->box.Centered(associated.box.Center());

    this->box.x = this->box.x + Vec2::Rotate(offset, associated.angleDeg*PI/180).x;
    this->box.y = this->box.y + Vec2::Rotate(offset, associated.angleDeg*PI/180).y;
}

void Collider::Render(){}

bool Collider::Is(std::string type){
    if(type.compare("Collider") == 0){
        return true;
    }

    return false;
}

void Collider::SetScale(Vec2 scale) { this->scale = scale; }
void Collider::SetOffset(Vec2 offset) { this->offset = offset; }