#ifndef STATE_H
#define STATE_H

#include "Music.h"
#include "Sprite.h"
#include "memory"

/**
 * @brief Class responsible for controlling the screen and specific internal logics.
 */
class State{
    private:
        /**
         * @brief soundtrack of the game 
         */
        Music music;
        /**
         * @brief control signal for exiting the game 
         */
        bool quitRequested;
        /**
         * @brief GameObject array
         * 
         */
        std::vector<std::unique_ptr<GameObject>> objectArray;

        /**
         * @brief take care of user inputs
         * 
         */
        void Input();

        /**
         * @brief Add an object to object array
         * 
         * @param mouseX 
         * @param mouseY 
         */
        void AddObject(int mouseX, int mouseY);

    public:
        /**
         * @brief construct a new State object, instantiating background and music
         */
        State();

        /**
         * @brief clear object array
         * 
         */
        ~State();

        /**
         * @brief returns the quitrequested variable
         * 
         * @return true 
         * @return false 
         */
        bool QuitRequested();

        /**
         * @brief Will be used for loading assets in the future 
         */
        void LoadAssets();

        /**
         * @brief Update game features, right now just check if quit was requested
         * 
         * @param dt 
         */
        void Update(float dt);

        /**
         * @brief render background on game window 
         */
        void Render();
};
#endif
