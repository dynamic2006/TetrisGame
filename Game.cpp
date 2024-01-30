#include "Game.h"
#include <raylib.h>
#include <assert.h>
#include "Settings.h"

Game::Game(int width, int height, int fps, std::string title)
    :
    board(settings::boardPosition, 
    settings::boardWidthHeight, 
    settings::cellSize, 
    settings::padding),
    tetromino(board)
{
    assert(!GetWindowHandle()); // if assertion triggers: window is already opened
    SetTargetFPS(fps);
    InitWindow(width, height, title.c_str());
}

Game::~Game() noexcept
{
    assert(GetWindowHandle()); // if assertion triggers: Window is already closed
    CloseWindow();
}

bool Game::GameShouldClose() const
{
    return WindowShouldClose();
}

void Game::Tick()
{
    BeginDrawing();
    Update();
    Draw();
    EndDrawing();
}

void Game::Draw()
{
    ClearBackground(BLACK);
    board.Draw();
    tetromino.Draw();
}

void Game::Update()
{
}
