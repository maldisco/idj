#include "Resources.h"
#include "Game.h"

std::unordered_map<std::string, std::shared_ptr<SDL_Texture>> Resources::imageTable;
std::unordered_map<std::string, Mix_Music*> Resources::musicTable;
std::unordered_map<std::string, Mix_Chunk*> Resources::soundTable;

std::shared_ptr<SDL_Texture> Resources::GetImage(std::string file){
    if(imageTable.find(file) != imageTable.end()){
        return imageTable[file];
    }

    SDL_Texture* texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    imageTable[file] = std::shared_ptr<SDL_Texture>(texture, [](SDL_Texture* ptr) {SDL_DestroyTexture(ptr);});
    return imageTable[file];
}

void Resources::ClearImages(){
    for(auto& image : imageTable){
        if(image.second.unique()){
            imageTable.erase(image.first);
        }
    }
}

Mix_Music* Resources::GetMusic(std::string file){
    if(musicTable.find(file) != musicTable.end()){
        return musicTable[file];
    }

    musicTable[file] = Mix_LoadMUS(file.c_str());
    return musicTable[file];
}

void Resources::ClearMusics(){
    for(auto& music : musicTable){
        Mix_FreeMusic(music.second);
    }

    musicTable.clear();
}

Mix_Chunk* Resources::GetSound(std::string file){
    if(soundTable.find(file) != soundTable.end()){
        return soundTable[file];
    }

    soundTable[file] = Mix_LoadWAV(file.c_str());
    return soundTable[file];
}

void Resources::ClearSounds(){
    for(auto& sound : soundTable){
        Mix_FreeChunk(sound.second);
    }

    soundTable.clear();
}