#include "Block.h"
#include "Colors.h"

Block::Block(){

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
            if(shape[r*dimension + c]) {DrawRectangle(c*CELLSIZE + 1, r*CELLSIZE + 1, CELLSIZE-1, CELLSIZE-1, COLORS[id]);}
        }
    }
}

//TO DO
//[ ] collisions
//[ ] right & left arrow keys move
//[ ] dropping blocks
