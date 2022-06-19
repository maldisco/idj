#include "SDL_image.h"
#include "SDL_mixer.h"
#include "Game.h"
#include <iostream>

// Definição dos métodos da classe Game
Game* Game::instance;
Game& Game::GetInstance()
{
    if (instance == nullptr)
    {
        new Game("Filipe de Sousa Fernandes - 202065879", 1024, 600);
    }

    return *instance;
}

Game::Game(std::string title, int width, int height)
{
    if (instance != nullptr)
    {
        std::cout << "Já tem uma instancia criada doidão";
    }

    instance = this;

    /* Initialization of basic SDL functionalities. */
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0)
    {
        SDL_Log("Unable to initialize IMG: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if (Mix_Init(MIX_INIT_OGG) == 0)
    {
        SDL_Log("Unable to initialize MIX: %s", SDL_GetError());
    }

    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0)
    {
        SDL_Log("Unable to initialize OpenAudio: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    Mix_AllocateChannels(32);

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if(window == nullptr){
        SDL_Log("Unable to initialize window: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr){
        SDL_Log("Unable to initialize renderer: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    state = new State();
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
    while (!(state->QuitRequested()))
    {
        state->Update(0);
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
}


