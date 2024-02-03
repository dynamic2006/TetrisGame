#include "Game.h"
#include <random>
#include <iostream>

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock()
{
    if(blocks.empty()){
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block b = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return b;
}

std::vector<Block> Game::GetAllBlocks()
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();
    switch(keyPressed)
    {
        case KEY_LEFT:
            MoveBlockLeft();
            break;
        case KEY_RIGHT:
            MoveBlockRight();
            break;
        case KEY_DOWN:
            MoveBlockDown();
            break;
        case KEY_UP:
            Rotate();
            break;
    }
}

void Game::ShiftBlock()
{
    int state = -1;
    while(state != 0){
        state = currentBlock.IsBlockOutside(grid.ROWS, grid.COLS);
        switch(state)
        {
            case 1:
                currentBlock.Move(0,1);
                break;
            case 2:
                currentBlock.Move(0,-1);
                break;
            case 3:
                currentBlock.Move(1,0);
                break;
            case 4:
                currentBlock.Move(-1,0);
                break;
        }
    }
}

void Game::MoveBlockLeft()
{
    currentBlock.Move(0,-1);
    ShiftBlock();
}

void Game::MoveBlockRight()
{
    currentBlock.Move(0,1);
    ShiftBlock();
}

void Game::MoveBlockDown()
{
    currentBlock.Move(1,0);
    ShiftBlock();

    if(currentBlock.AtBottom(grid.ROWS)) LockBlock();
}

void Game::Rotate()
{
    currentBlock.Rotate();
    ShiftBlock();
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}

void Game::LockBlock()
{
    std::vector<bool> shape = currentBlock.GetShape();
    int d = currentBlock.GetDimension();
    int id = currentBlock.GetId();
    for(int r=0; r<d; r++){
        for(int c=0; c<d; c++){
            if(shape[r*d + c]) grid.values[r+currentBlock.GetRowOffset()][c+currentBlock.GetColOffset()] = id;
        }
    }
    currentBlock = nextBlock;
    nextBlock = GetRandomBlock();
}
