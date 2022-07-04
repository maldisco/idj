#ifndef SOUND_H
#define SOUND_H

#include "Component.h"
#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

/**
 * @brief sound effects of game objects
 * 
 */
class Sound : public Component{
    public:
        Sound(GameObject& associated);
        Sound(std::string file, GameObject& associated);

        ~Sound();

        void Play(int times = 1);
        void Stop();

        void Open(std::string file);
        bool IsOpen();

        void Update(float dt);
        void Render();

        bool Is(std::string type);

    private:
        Mix_Chunk* chunk;
        int channel;
};
#endif