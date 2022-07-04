#include "Music.h"
#include "Sprite.h"

/**
 * @brief Class responsible for controlling the screen and specific internal logics.
 */
class State{
    private:
        /**
         * @brief encapsulates an SDL_Texture (used as background)
         */
        Sprite bg;
        /**
         * @brief soundtrack of the game 
         */
        Music music;
        /**
         * @brief control signal for exiting the game 
         */
        bool quitRequested;

    public:
        /**
         * @brief construct a new State object, instantiating background and music
         */
        State();

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