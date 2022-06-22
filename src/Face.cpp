#include "Face.h"
#include "Sound.h"

Face::Face(GameObject& associated) : Component(associated), hitpoints(30){}

void Face::Damage(int damage){
    hitpoints -= 30;

    if (hitpoints <= 0){
        associated.RequestDelete();
        Sound* sound = (Sound*)associated.GetComponent("Sound");
        sound->Play();
    }
}

Face::~Face(){}

void Face::Update(float dt){}

void Face::Render(){}

bool Face::Is(std::string type){
    if(type == "Face"){
        return true;
    }

    return false;
}