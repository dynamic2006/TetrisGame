#include <iostream>
#include "Grid.h"
#include "Colors.h"

Grid::Grid()
{
    Initialize();
}

void Grid::Initialize()
{
    for(int row=0; row < ROWS; row++){
        for(int col=0; col < COLS; col++){
            values[row][col] = false;
        }
    }
}

void Grid::Print()
{
    for(int row=0; row < ROWS; row++){
        for(int col=0; col < COLS; col++){
            std::cout << values[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw()
{
    for(int row=0; row < ROWS; row++){
        for(int col=0; col < COLS; col++){
            int cellValue = values[row][col];
            DrawRectangle(col*CELLSIZE + 1, row*CELLSIZE + 1, CELLSIZE - 1, CELLSIZE - 1, COLORS[cellValue]);
        }
    }
}