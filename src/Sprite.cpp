#include "Game.h"
#include "Resources.h"
#include "Camera.h"

#include <iostream>

#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"

Sprite::Sprite(GameObject& associated) : Component(associated), texture(nullptr) {}

Sprite::Sprite(std::string file, GameObject& associated) : Component(associated), texture(nullptr) {
    Open(file);
}

Sprite::~Sprite(){}

void Sprite::Open(std::string file){
    texture = Resources::GetImage(file);

    if (texture == nullptr){
        SDL_Log("Cant load bg: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
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
    dstrect.w = clipRect.w;
    dstrect.h = clipRect.h;

    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect);
}

void Sprite::Render(){
    Render(associated.box.x, associated.box.y);
}

int Sprite::GetWidth(){
    return width;
}

int Sprite::GetHeight(){
    return height;
}

bool Sprite::IsOpen(){
    return texture != nullptr;
}
