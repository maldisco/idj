#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"

#include <string>

/**
 * @brief Only encapsulates an SDL_Texture.
 */
class Sprite{
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
         * @brief intializes texture as nullptr 
         */
        Sprite();
        
        /**
         * @brief initializes texture as the image on the address passed as file
         * 
         * @param file 
         */
        Sprite(std::string file);

        /**
         * @brief destroy the Sprite (and SDL_Texture) object
         * 
         */
        ~Sprite();

        /**
         * @brief opens an image on the 'file' address
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
         * @brief call game renderer to render texture on positions x and y
         * 
         * @param x 
         * @param y 
         */
        void Render(int x, int y);

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