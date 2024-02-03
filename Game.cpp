#include "Game.h"
#include <random>
#include <iostream>

Game::Game()
{
    Reset();
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
    if(gameOver && keyPressed != 0){
        Reset();
    }
    else if(gameOver) return;
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
            UpdateScore(0,1);
            break;
        case KEY_UP:
            Rotate();
            break;
    }
}

void Game::AdjustBlock()
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
    if(gameOver) return;
    currentBlock.Move(0,-1);
    AdjustBlock();
    if(BlockCollides()){
        currentBlock.Move(0,1);
    }

}

void Game::MoveBlockRight()
{
    if(gameOver) return;
    currentBlock.Move(0,1);
    AdjustBlock();
    if(BlockCollides()){
        currentBlock.Move(0,-1);
    }
}

void Game::MoveBlockDown()
{
    if(gameOver) return;
    currentBlock.Move(1,0);
    AdjustBlock();
    if(BlockCollides()){
        currentBlock.Move(-1,0);
        LockBlock();
    }
    else if(currentBlock.AtBottom(grid.ROWS)) LockBlock();
}

void Game::Rotate()
{
    if(gameOver) return;
    currentBlock.Rotate();
    if(BlockCollides()) currentBlock.UndoRotate();
    AdjustBlock();
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw(11, 11);\
    switch(nextBlock.GetId()){
        case 3:
            nextBlock.Draw(255, 290);
            break;
        case 4:
            nextBlock.Draw(255, 280);
            break;
        default:
            nextBlock.Draw(270, 270);
            break;
    }
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
    if(BlockCollides()){
        gameOver = true;
    }
    nextBlock = GetRandomBlock();
    int rowsCleared = grid.ClearFullRows();
    UpdateScore(rowsCleared, 0);
}

void Game::UpdateScore(int linesCleared, int moveDownPoints)
{
    switch (linesCleared)
    {
        case 1:
            score += 100;
            break;
        case 2:
            score += 300;
            break;
        case 3:
            score += 500;
            break;
        default:
            break;
    }

    score += moveDownPoints;
}

bool Game::BlockCollides()
{
    std::vector<bool> shape = currentBlock.GetShape();
    int d = currentBlock.GetDimension();
    for(int r=0; r<d; r++){
        for(int c=0; c<d; c++){
            if(shape[r*d+c]) {
                int gridRows = currentBlock.GetRowOffset() + r;
                int gridCols = currentBlock.GetColOffset() + c;
                if(grid.values[gridRows][gridCols]){
                    return true;
                }
            }
        }
    }
    return false;
}

bool Game::GetGameOver()
{
    return gameOver;
}

void Game::Reset()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    score = 0;
}
