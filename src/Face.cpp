#include "Face.h"
#include "Sound.h"
#include "InputManager.h"
#include "Camera.h"
#include <iostream>

Face::Face(GameObject& associated) : Component(associated), hitpoints(30){}

void Face::Damage(int damage){
    hitpoints -= damage;

    if (hitpoints <= 0){
        associated.RequestDelete();
        Sound* sound = (Sound*)associated.GetComponent("Sound");
        sound->Play();
    }
}

Face::~Face(){}

void Face::Update(float dt){
    if(InputManager::GetInstance().MousePress(LEFT_MOUSE_BUTTON)){
        if(associated.box.Contains( {(float)InputManager::GetInstance().GetMouseX(), (float)InputManager::GetInstance().GetMouseY()} )){
            Damage(std::rand() % 10 + 10);
        }
    }
}

void Face::Render(){}

bool Face::Is(std::string type){
    if(type.compare("Face") == 0){
        return true;
    }

    return false;
}