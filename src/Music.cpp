#include "Music.h"

#include "SDL.h"

Music::Music() : music(nullptr){}

Music::Music(std::string file) : Music(){
    Open(file);
}

void Music::Play(int times){
    if (Mix_PlayMusic(music, times) == -1){
        SDL_Log("Cant play music: %s", SDL_GetError());
        
    }
}

void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(std::string file){
    music = Mix_LoadMUS(file.c_str());
    Mix_VolumeMusic(MIX_MAX_VOLUME/8);

    if (music == nullptr){
        SDL_Log("Cant load music: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

bool Music::IsOpen(){
    return music != nullptr;
}

Music::~Music(){
    Stop(1500);
    Mix_FreeMusic(music);
}