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
            values[row][col] = 0;
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
            DrawRectangle(col*CELLSIZE + 11, row*CELLSIZE + 11, CELLSIZE - 1, CELLSIZE - 1, COLORS[cellValue]);
        }
    }
}

bool Grid::IsRowFull(int row)
{
    for(int col=0; col<COLS; col++){
        if(values[row][col] == 0) return false;
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for(int col=0; col<COLS; col++){
        values[row][col] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRows)
{
    for(int col=0; col < COLS; col++){
        values[row+numRows][col] = values[row][col];
        values[row][col] = 0;
    }
}

int Grid::ClearFullRows()
{
    int completed = 0;
    for(int row = ROWS - 1; row >= 0; row--){
        if(IsRowFull(row)){
            ClearRow(row);
            completed++;
        }
        else if (completed > 0){
            MoveRowDown(row, completed);
        }
    }
    return completed;
}
