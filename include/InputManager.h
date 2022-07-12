#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#define INCLUDE_SDL
#include "SDL_include.h"

#define LEFT_ARROW_KEY     SDLK_LEFT
#define RIGHT_ARROW_KEY    SDLK_RIGHT
#define UP_ARROW_KEY       SDLK_UP
#define DOWN_ARROW_KEY     SDLK_DOWN
#define ESCAPE_KEY         SDLK_ESCAPE
#define LEFT_MOUSE_BUTTON  SDL_BUTTON_LEFT
#define RIGHT_MOUSE_BUTTON SDL_BUTTON_RIGHT


#include "unordered_map"

/**
 * @brief Encapsulates mouse and keyboard inputs
 */
class InputManager{
    public:
        void Update();

        bool KeyPress(int key);
        bool KeyRelease(int key);
        bool IsKeyDown(int key);

        bool MousePress(int button);
        bool MouseRelease(int button);
        bool IsMouseDown(int button);

        int GetMouseX();
        int GetMouseY();

        bool QuitRequested();

        static InputManager& GetInstance();
    
    private:
        InputManager();
        ~InputManager();

        bool mouseState[6];
        int mouseUpdate[6];

        std::unordered_map<int, bool> keyState;
        std::unordered_map<int, int> keyUpdate;


        bool quitRequested;

        int updateCounter;

        int mouseX;
        int mouseY;
};

#endif