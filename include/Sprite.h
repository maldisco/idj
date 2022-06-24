#ifndef SPRITE_H
#define SPRITE_H

#include "SDL_image.h"

#include "Component.h"

#include <string>

/**
 * @brief inherits from component. encapsulates an SDL_Texture
 * 
 */
class Sprite : public Component{
    private:
        /**
         * @brief object that holds a texture 
         */
        SDL_Texture* texture;
        /**
         * @brief rectangle specifying dimensions of the texture 
         */
        SDL_Rect clipRect;
        int width;
        int height;
    
    public:
        /**
         * @brief initialize texture as nullptr and call upper class constructor
         * 
         * @param associated 
         */
        Sprite(GameObject& associated);
        
        /**
         * @brief initialize texture as file and call upper class constructor
         * 
         * @param file 
         */
        Sprite(std::string file, GameObject& associated);

        /**
         * @brief destroy the Sprite (and SDL_Texture) object
         * 
         */
        ~Sprite();

        /**
         * @brief open file and set it to texture
         * 
         * @param file 
         */
        void Open(std::string file);

        /**
         * @brief Set the Clip object attrs
         * 
         * @param x 
         * @param y 
         * @param w 
         * @param h 
         */
        void SetClip(int x, int y, int w, int h);

        /**
         * @brief Render texture on given coordinates
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
         * @brief tells if texture is already loaded
         * 
         * @return true 
         * @return false 
         */
        bool IsOpen();
};
#endif