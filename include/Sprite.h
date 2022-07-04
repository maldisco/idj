#ifndef SPRITE_H
#define SPRITE_H

#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"

#include "Component.h"

#include <string>

/**
 * @brief Component responsible for in-game texture (image).
 * 
 */
class Sprite : public Component{
    private:
        /**
         * @brief Object that holds a texture 
         */
        SDL_Texture* texture;
        /**
         * @brief Rectangle specifying dimensions of the texture 
         */
        SDL_Rect clipRect;
        int width;
        int height;
    
    public:
        /**
         * @brief Initialize texture as nullptr
         * 
         * @param associated 
         */
        Sprite(GameObject& associated);
        
        /**
         * @brief Initializes texture as file
         * 
         * @param file 
         */
        Sprite(std::string file, GameObject& associated);
        ~Sprite();

        /**
         * @brief Load file into texture
         * 
         * @param file 
         */
        void Open(std::string file);

        /**
         * @brief Set the Clip object attributes
         * 
         * @param x 
         * @param y 
         * @param w 
         * @param h 
         */
        void SetClip(int x, int y, int w, int h);

        /**
         * @brief Render texture on game window at given coordinates
         * 
         * @param x 
         * @param y 
         */
        void Render(int x, int y);

        /**
         * @brief Render texture on game window 
         */
        void Render();

        void Update(float dt);
        bool Is(std::string type);

        /**
         * @brief Get the Width object
         * 
         * @return int 
         */
        int GetWidth();

        /**
         * @brief Get the Height object
         * 
         * @return int 
         */
        int GetHeight();
        
        /**
         * @brief Tell if texture is already loaded
         * 
         * @return true 
         * @return false 
         */
        bool IsOpen();
};
#endif