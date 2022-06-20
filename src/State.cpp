#include "State.h"

State::State() : quitRequested(false), bg("img/ocean.jpg"), music("audio/stageState.ogg")
{
    music.Play();
}

void State::LoadAssets(){}

void State::Update(float dt)
{
    if (SDL_QuitRequested() == true)
    {
        quitRequested = true;
    }
}

void State::Render()
{
    bg.Render(0, 0);
}

bool State::QuitRequested()
{
    return quitRequested;
}

