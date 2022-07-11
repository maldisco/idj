#include "Game.h"
#include "Resources.h"
#include "Camera.h"

#include <iostream>

#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"

Sprite::Sprite(GameObject& associated) : Component(associated), texture(nullptr) {}

Sprite::Sprite(std::string file, GameObject& associated) : Component(associated), texture(nullptr), scale({1, 1}) {
    Open(file);
}

Sprite::~Sprite(){}

void Sprite::Open(std::string file){
    texture = Resources::GetImage(file);

    if (texture == nullptr){
        SDL_Log("Cant load sprite: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    associated.box.w = width;
    associated.box.h = height;
    SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.h = h;
    clipRect.w = w;
    clipRect.x = x;
    clipRect.y = y;
}

void Sprite::Update(float dt){}

bool Sprite::Is(std::string type){
    if(type.compare("Sprite") == 0){
        return true;
    }

    return false;
}

void Sprite::Render(int x, int y){
    SDL_Rect dstrect;
    dstrect.x = x;
    dstrect.y = y;
    dstrect.w = clipRect.w*this->GetScale().x;
    dstrect.h = clipRect.h*this->GetScale().y;

    SDL_RenderCopyEx(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect, associated.angleDeg, nullptr, SDL_FLIP_NONE);
}

void Sprite::Render(){
    Render(associated.box.x - Camera::pos.x, associated.box.y - Camera::pos.y);
}

void Sprite::SetScaleX(float scaleX, float scaleY){
    // % of increase/decrease in size rate
    float widthChangeRate = scaleX - scale.x;
    float heightChangeRate = scaleY - scale.y;

    // absolute value of increase/decrease 
    float widthChange = associated.box.w*widthChangeRate;
    float heightChange = associated.box.h*heightChangeRate;

    // rescale associated box
    associated.box.w += widthChange;
    associated.box.h += heightChange;
    associated.box.x -= widthChange/2;
    associated.box.y -= heightChange/2;

    scale.x = scaleX;
    scale.y = scaleY;
}

Vec2 Sprite::GetScale(){ return scale; }

int Sprite::GetWidth(){
    return width*scale.x;
}

int Sprite::GetHeight(){
    return height*scale.y;
}

bool Sprite::IsOpen(){
    return texture != nullptr;
}
