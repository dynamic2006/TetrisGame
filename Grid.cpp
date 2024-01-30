#include <iostream>
#include "Grid.h"

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = getCellColors();
}

void Grid::Initialize()
{
    for(int row=0; row < numRows; row++){
        for(int col=0; col < numCols; col++){
            grid[row][col] = 0;
        }
    }
}

void Grid::Print()
{
    for(int row=0; row < numRows; row++){
        for(int col=0; col < numCols; col++){
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw()
{
    for(int row=0; row < numRows; row++){
        for(int col=0; col < numCols; col++){
            int cellValue = grid[row][col];
            DrawRectangle(col*cellSize + 1, row*cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

std::vector<Color> Grid::getCellColors()
{
    Color darkGray = {26, 31, 40, 255};
    Color green = {47, 230, 23, 255};
    Color red = {232, 18, 18, 255};
    Color orange = {226, 116, 17, 255};
    Color yellow = {237, 234, 4, 255};
    Color purple = {166, 0, 247, 255};
    Color cyan = {21, 204, 209, 255};
    Color blue = {13, 64, 216, 255};

    return {darkGray, green, red, orange, yellow, purple, cyan, blue};
}
