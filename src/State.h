#include "Music.h"
#include "Sprite.h"

/**
 * @brief Class responsible for controlling the screen and specific internal logics.
 */
class State{
    private:
        Sprite bg;
        Music music;
        bool quitRequested;

    public:
        State();

        bool QuitRequested();

        void LoadAssets();

        void Update(float dt);

        void Render();
};