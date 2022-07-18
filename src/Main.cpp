#include "Game.h"
#include "StageState.h"

int main(int argc, char **argv)
{   
    Game game = Game::GetInstance();
    State* initialState = new StageState();
    game.Push(initialState);
    game.Run();

    return 0;
}