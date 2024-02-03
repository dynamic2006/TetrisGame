#pragma once
#include "Grid.h"
#include "Block.h"

class Game{
    public:
        Grid grid;
        bool gameOver;
        int score = 0;

        Game();
        Block GetRandomBlock();
        std::vector<Block> GetAllBlocks();
        void HandleInput();
        void AdjustBlock(); //shifts a block that is outside border
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();
        void Rotate();
        void Draw();
        void LockBlock();
        void UpdateScore(int linesCleared, int moveDownPoints);
        
        bool BlockCollides();
        bool GetGameOver();
        void Reset();
    
    private:
        std::vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
};