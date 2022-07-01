#include "InputManager.h"

InputManager& InputManager::GetInstance(){
    static InputManager inputManager;
    return inputManager;
}

InputManager::InputManager(){
    mouseState;
    mouseUpdate;
    quitRequested;
    updateCounter;
    mouseX;
    mouseY;
}

InputManager::~InputManager(){}