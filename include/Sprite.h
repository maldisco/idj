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
        Vec2 scale;
        int width;
        int height;
        int frameCount;
        int currentFrame;
        float timeElapsed;
        float frameTime;
    
    public:
        /**
         * @brief Initialize texture as nullptr
         * 
         * @param associated 
         */
        Sprite(GameObject& associated, int frameCount, float frameTime);
        
        /**
         * @brief Initializes texture as file
         * 
         * @param file 
         * @param associated 
         * @param frameCount 
         * @param frameTime 
         */
        Sprite(std::string file, GameObject& associated, int frameCount = 1, float frameTime = 1);
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
         * @brief Set the Frame object
         * 
         * @param frame 
         */
        void SetFrame(int frame);

        /**
         * @brief Set the Frame Count object
         * 
         * @param frameCount 
         */
        void SetFrameCount(int frameCount);

        /**
         * @brief Set the Frame Time object
         * 
         * @param frameTime 
         */
        void SetFrameTime(float frameTime);

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
         * @brief Set sprite scale (size)
         * 
         * @param scaleX 
         * @param scaleY 
         */
        void SetScaleX(float scaleX, float scaleY);
        Vec2 GetScale();

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