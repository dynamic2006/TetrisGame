#include <raylib.h>
#include <iostream>
#include "Grid.h"
#include "Block.h"


int main()
{
    InitWindow(300, 600, "Tetris");
    SetTargetFPS(60);

    Grid grid = Grid();
    // grid.values[0][0] = 1;
    // grid.values[3][5] = 4;
    grid.Print();

    //std::cout << "CHECKPOINT" << std::endl;

    while(!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(DARKBLUE);
        grid.Draw();
        Block J = JBlock();
        J.Rotate();
        J.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}