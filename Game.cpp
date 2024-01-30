#include "Game.h"
#include <raylib.h>
#include <assert.h>
#include "Settings.h"

Game::Game(int width, int height, int fps, std::string title)
    :
    board(settings::boardPosition, 
    settings::boardWidthHeight, 
    settings::cellSize, 
    settings::padding)
{
    assert(!GetWindowHandle()); // if assertion triggers: window is already opened
    SetTargetFPS(fps);
    InitWindow(width, height, title.c_str());
    for(int iy = 0; iy < 20; iy++){
        for(int ix = 0; ix < 10; ix++){
            board.SetCell({ix, iy}, RED);
        }
    }
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
}

void Game::Update()
{
}
