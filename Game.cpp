#include "Game.h"
#include <random>

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
    int state = currentBlock.IsBlockOutside(grid.ROWS, grid.COLS);
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
}

void Game::Rotate()
{
    currentBlock.Rotate();
    int state = currentBlock.IsBlockOutside(grid.ROWS, grid.COLS);
    ShiftBlock();
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw();
}
