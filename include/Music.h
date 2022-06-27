#ifndef MUSIC_H
#define MUSIC_H

#include <string>

#include "SDL_mixer.h"

/**
 * @brief Responsible for soundtrack. Opens and plays a music.
 */
class Music{
    private:
        /**
         * @brief object that holds a music file 
         */
        Mix_Music* music;
    
    public:
        /**
         * @brief only initializes music as nullptr
         * 
         */
        Music();

        /**
         * @brief initializes music as the archive passed
         * 
         * @param file 
         */
        Music(std::string file);

        /**
         * @brief stop and destroy music
         * 
         */
        ~Music();

        /**
         * @brief play music 'times' times
         * 
         * @param times 
         */
        void Play(int times = -1);

        /**
         * @brief stop the music with a fade of 'msToStop' milisseconds
         * 
         * @param msToStop 
         */
        void Stop(int msToStop = 1500);

        /**
         * @brief open music file
         * 
         * @param file 
         */
        void Open(std::string file);

        /**
         * @brief tells if a music is already loaded
         * 
         * @return true 
         * @return false 
         */
        bool IsOpen();
};
#endif