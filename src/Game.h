#include "SDL.h"

#include "State.h"

/**
 * @brief Class responsible for initializating/liberating resources and running main loop
 */
class Game {
    private:
        /**
         * @brief Instantiate a Game object and initialize SDL libraries
         * 
         * @param title 
         * @param width 
         * @param height 
         */
        Game(std::string title, int width, int height);
        
        /**
         * @brief Unique instance of Game (Singleton) 
         */
        static Game* instance;

        /**
         * @brief Game window 
         */
        SDL_Window* window;
        /**
         * @brief Responsible for filling the window 
         */
        SDL_Renderer* renderer;
        /**
         * @brief Object that controls the state of the game 
         */
        State* state;
    
    public:
        /**
         * @brief Destroy the state object and quit all SDL functionalities 
         */
        ~Game();

        /**
         * @brief The game loop 
         */
        void Run();

        /**
         * @brief Get the Renderer object
         * 
         * @return SDL_Renderer* 
         */
        SDL_Renderer* GetRenderer();

        /**
         * @brief Get the State object
         * 
         * @return State& 
         */
        State& GetState();

        /**
         * @brief Get the only instance of Game class
         * 
         * @return Game& 
         */
        static Game& GetInstance();
};