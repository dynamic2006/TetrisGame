#include "Block.h"
#include "Colors.h"

Block::Block(){
    rowOffset = 0;
    colOffset = 0;
}

void Block::Rotate()
{
    std::vector<bool> newShape;
    for(int r=0; r<dimension; r++){
        for(int c=0; c<dimension; c++){
            newShape.push_back(shape[dimension*(dimension-1) - dimension*c + r]);
        }
    }
    this->shape = newShape;
}

void Block::Draw()
{
    for(int r=0; r<dimension; r++){
        for(int c=0; c<dimension; c++){
            if(shape[r*dimension + c]){
                DrawRectangle((c+colOffset)*CELLSIZE + 1, (r+rowOffset)*CELLSIZE + 1, CELLSIZE-1, CELLSIZE-1, COLORS[id]);
            }
        }
    }
}

void Block::Move(int rows, int cols)
{
    rowOffset += rows;
    colOffset += cols;
}

int Block::IsBlockOutside(int gridRows, int gridCols)
{
    for(int r=0; r<dimension; r++){
        for(int c=0; c<dimension; c++){
            if(shape[r*dimension + c]){
                if((colOffset + c) < 0) return 1; //outside left border
                if((colOffset + c) >= gridCols) return 2; //outside right border
                if((rowOffset + r) < 0) return 3; //outside upper border
                if((rowOffset + r) >= gridRows) return 4; //outside lower border
            }
        }
    }
    return 0;
}

bool Block::AtBottom(int gridRows)
{
    for(int r=0; r<dimension; r++){
        for(int c=0; c<dimension; c++){
            if(shape[r*dimension + c] && rowOffset + r == gridRows - 1) return true;
        }
    }
    return false;
}

std::vector<bool> Block::GetShape()
{
    return shape;
}

int Block::GetRowOffset()
{
    return rowOffset;
}

int Block::GetColOffset()
{
    return colOffset;
}

int Block::GetDimension()
{
    return dimension;
}

int Block::GetId()
{
    return id;
}

//TO DO
//[ ] collisions
//[X] right & left arrow keys move
//[ ] dropping blocks
