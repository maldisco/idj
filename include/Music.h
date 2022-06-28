#ifndef MUSIC_H
#define MUSIC_H

#include <string>

#include "SDL_mixer.h"

/**
 * @brief Class responsible for soundtrack management.
 */
class Music{
    private:
        /**
         * @brief Object that holds a music file 
         */
        Mix_Music* music;
    
    public:
        /**
         * @brief Initializes music as nullptr
         * 
         */
        Music();

        /**
         * @brief Initializes music as file
         * 
         * @param file 
         */
        Music(std::string file);
        ~Music();

        /**
         * @brief Play music a number of times (-1 for infinite)
         * 
         * @param times 
         */
        void Play(int times = -1);

        /**
         * @brief Stop the music with a fade out
         * 
         * @param msToStop 
         */
        void Stop(int msToStop = 1500);

        /**
         * @brief Load file into music
         * 
         * @param file 
         */
        void Open(std::string file);

        /**
         * @brief Tell if music is already loaded
         * 
         * @return true 
         * @return false 
         */
        bool IsOpen();
};
#endif