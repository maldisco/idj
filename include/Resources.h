#ifndef RESOURCES_H
#define RESOURCES_h

#include "unordered_map"
#include <string>
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"

/**
 * @brief Class that load, alocate and desalocate all resources.
 * 
 */
class Resources{
    public:

        /**
         * @brief Load an image
         * 
         * @param file 
         * @return SDL_Texture* 
         */
        static SDL_Texture* GetImage(std::string file);
        /**
         * @brief Clear images map
         * 
         */
        static void ClearImages();

        /**
         * @brief Load a music
         * 
         * @param file 
         * @return Mix_Music* 
         */
        static Mix_Music* GetMusic(std::string file);
        /**
         * @brief Clear musics map
         * 
         */
        static void ClearMusics();

        /**
         * @brief Load a sound
         * 
         * @param file 
         * @return Mix_Chunk* 
         */
        static Mix_Chunk* GetSound(std::string file);
        /**
         * @brief Clear sounds map
         * 
         */
        static void ClearSounds();

    private:
        /**
         * @brief Maps will be used for memory usage improvement
         * 
         */
        static std::unordered_map<std::string, SDL_Texture*> imageTable;
        static std::unordered_map<std::string, Mix_Music*> musicTable;
        static std::unordered_map<std::string, Mix_Chunk*> soundTable;
};
#endif