#pragma once
#include "Grid.h"
#include "Block.h"

class Game{
    public:
        Grid grid;

        Game();
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        void HandleInput();
        void ShiftBlock(); //shifts a block that is outside border
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();
        void Rotate();
        void Draw();
    
    private:
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
};