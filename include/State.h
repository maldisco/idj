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
         * @brief Soundtrack 
         */
        Music music;
        /**
         * @brief Control signal for exiting the game 
         */
        bool quitRequested;
        /**
         * @brief GameObject array
         * 
         */
        std::vector<std::shared_ptr<GameObject>> objectArray;

        bool started;

        /**
         * @brief Take care of user inputs (temp)
         * 
         */
        void Input();

    public:
        /**
         * @brief Construct a new State object, instantiating background and music
         */
        State();

        /**
         * @brief Clear object array
         * 
         */
        ~State();

        /**
         * @brief Tell if game was closed
         * 
         * @return true 
         * @return false 
         */
        bool QuitRequested();

        /**
         * @brief Update game objects
         * 
         * @param dt 
         */
        void Update(float dt);

        /**
         * @brief Render game objects
         */
        void Render();

        void LoadAssets();

        void Start();

        std::weak_ptr< GameObject > AddObject(GameObject* go);

        std::weak_ptr< GameObject > GetObjectPtr(GameObject* go);
};
#endif