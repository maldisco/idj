#include "Sound.h"
#include "iostream"


Sound::Sound(GameObject& associated) : Component(associated), chunk(nullptr){}

Sound::Sound(std::string file, GameObject& associated) : Sound(associated){
    Open(file);
}

void Sound::Update(float dt){}

bool Sound::Is(std::string type){
    if(type.compare("Sound") == 0){
        return true;
    }

    return false;
}

void Sound::Render(){}

void Sound::Play(int times){
    if(chunk == nullptr){
        SDL_Log("Cant load sound: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    channel = Mix_PlayChannel(-1, chunk, times-1);
    if(channel == -1){
        SDL_Log("Cant play sound: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

void Sound::Stop(){
    if(chunk != nullptr){
        Mix_HaltChannel(channel);
    }
}

void Sound::Open(std::string file){
    chunk = Mix_LoadWAV(file.c_str());
    if(chunk == nullptr){
        SDL_Log("Cant load sound: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

Sound::~Sound(){
    if(chunk != nullptr){
        Mix_HaltChannel(channel);
        Mix_FreeChunk(chunk);
    }
}