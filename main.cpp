#include <raylib.h>
#include "Game.h"


int main()
{
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Game game = Game();

    while(!WindowShouldClose())
    {
        game.HandleInput();
        BeginDrawing();

        ClearBackground(DARKBLUE);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}