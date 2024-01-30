#include "Game.h"
#include "Settings.h"

int main() {

    Game game(
    settings::SCREENWIDTH, 
    settings::SCREENHEIGHT, 
    settings::fps, 
    "Tetris Raylib");

    while(!game.GameShouldClose())
    {
        game.Tick();
    }

    return 0;
}