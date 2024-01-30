#include "Game.h"

int main() {
    
    const int SCREENWIDTH = 800;
    const int SCREENHEIGHT = 600;

    Game game(SCREENWIDTH, SCREENHEIGHT, 60, "Tetris Raylib");

    while(!game.GameShouldClose())
    {
        game.Tick();
    }

    return 0;
}