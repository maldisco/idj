#include "SDL_image.h"

#include <string>

/**
 * @brief Only encapsulates an SDL_Texture.
 */
class Sprite{
    private:
        SDL_Texture* texture;
        SDL_Rect clipRect;
        int width;
        int height;
    
    public:
        Sprite();

        Sprite(std::string file);

        ~Sprite();

        void Open(std::string file);

        void SetClip(int x, int y, int w, int h);

        void Render(int x, int y);

        int GetWidth();

        int GetHeight();

        bool IsOpen();
};