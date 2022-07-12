#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "Game.h"
#include "InputManager.h"
#include "Resources.h"
#include <ctime>

Game* Game::instance;
Game& Game::GetInstance()
{
    if (instance == nullptr)
    {
        new Game("Filipe de Sousa Fernandes - 202065879", 1024, 600);
    }

    return *instance;
}

Game::Game(std::string title, int width, int height) : frameStart(0), dt(0)
{
    instance = this;

    // Initialization of basic SDL functionalities 
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0)
    {
        SDL_Log("Cant initialize SDL: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0)
    {
        SDL_Log("Cant initialize IMG: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if (Mix_Init(MIX_INIT_OGG) == 0)
    {
        SDL_Log("Cant initialize MIX: %s", SDL_GetError());
    }

    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0)
    {
        SDL_Log("Cant initialize OpenAudio: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    Mix_AllocateChannels(32);

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if(window == nullptr){
        SDL_Log("Cant initialize window: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr){
        SDL_Log("Cant initialize renderer: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    frameStart = SDL_GetTicks();
    state = new State();

    srand(time(NULL));
}

Game::~Game()
{   
    delete state;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

State& Game::GetState()
{
    return *state;
}

SDL_Renderer* Game::GetRenderer()
{
    return renderer;
}

void Game::Run()
{
    state->Start();
    while (!(state->QuitRequested()))
    {
        CalculateDeltaTime();
        InputManager::GetInstance().Update();
        state->Update(GetDeltaTime());
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }

    Resources::ClearImages();
    Resources::ClearMusics();
    Resources::ClearSounds();
}

void Game::CalculateDeltaTime(){
    dt = (SDL_GetTicks() - frameStart);
    frameStart = SDL_GetTicks();
}

float Game::GetDeltaTime(){ return dt/1000; }

