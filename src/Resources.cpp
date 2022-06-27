#include "Resources.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
#include "Game.h"


SDL_Texture* Resources::GetImage(std::string file){
    if(imageTable.find(file) != imageTable.end()){
        return imageTable[file];
    }

    imageTable[file] = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    return imageTable[file];
}

void Resources::ClearImages(){
    for(std::pair<std::string, SDL_Texture*> image : imageTable){
        SDL_DestroyTexture(image.second);
    }

    imageTable.clear();
}

Mix_Music* Resources::GetMusic(std::string file){
    if(musicTable.find(file) != musicTable.end()){
        return musicTable[file];
    }

    musicTable[file] = Mix_LoadMUS(file.c_str());
    return musicTable[file];
}

void Resources::ClearMusics(){
    for(std::pair<std::string, Mix_Music*> music : musicTable){
        Mix_FreeMusic(music.second);
    }
}

Mix_Chunk* Resources::GetSound(std::string file){
    if(soundTable.find(file) != soundTable.end()){
        return soundTable[file];
    }

    soundTable[file] = Mix_LoadWAV(file.c_str());
    return soundTable[file];
}

void Resources::ClearSounds(){
    for(std::pair<std::string, Mix_Chunk*> sound : soundTable){
        Mix_FreeChunk(sound.second);
    }
}