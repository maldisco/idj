#include "PenguinBody.h"
#include "PenguinCannon.h"
#include "Sprite.h"
#include "Game.h"
#include "InputManager.h"

PenguinBody* PenguinBody::player;
PenguinBody::PenguinBody(GameObject& associated) : Component(associated), linearSpeed(0), speed({0,0}), angle(0), hp(100){
    player = this;

    associated.AddComponent(new Sprite("assets/img/penguin.png", associated));
}

PenguinBody::~PenguinBody(){
    player = nullptr;
}

void PenguinBody::Start(){
    std::cout << "entra penguin body start" << std::endl;
    GameObject* go = new GameObject();
    go->AddComponent(new PenguinCannon(*go, Game::GetInstance().GetState().GetObjectPtr(&associated)));
    this->pcannon = Game::GetInstance().GetState().AddObject(go);
    std::cout << "sai penguin body start" << std::endl;
}

void PenguinBody::Update(float dt){
    if(InputManager::GetInstance().IsKeyDown(W_KEY)){
        linearSpeed = std::min(linearSpeed+5, float(100));
    } 
    if (InputManager::GetInstance().IsKeyDown(S_KEY)){
        linearSpeed = std::max(linearSpeed-5, float(-100));
    } 
    if (InputManager::GetInstance().IsKeyDown(A_KEY)){
        angle = -PI/2;   
    } 
    if (InputManager::GetInstance().IsKeyDown(D_KEY)){
        angle = PI/2;
    }   
    
    associated.box.x += (speed*linearSpeed).Rotate(angle).x*dt;
    associated.box.y += (speed*linearSpeed).Rotate(angle).y*dt;

    if(hp <= 0){
        associated.RequestDelete();
        pcannon.lock()->RequestDelete();
    }
}

void PenguinBody::Render(){}

bool PenguinBody::Is(std::string type){
    if(type.compare("Penguin body") == 0){
        return true;
    }

    return false;
}