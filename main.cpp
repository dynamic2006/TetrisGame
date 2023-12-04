#include "Game.h"

int main(void)
{
    //Initialization

    const int SCREENWIDTH = 800;
    const int SCREENHEIGHT = 450;

    Game game(SCREENWIDTH, SCREENHEIGHT, 60, "Tetris");

    while(!game.GameShouldClose()){
        game.Tick();
    }

    return 0;
}