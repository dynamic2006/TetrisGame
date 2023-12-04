#include "Game.h"
#include "raylib.h"
#include <assert.h>

Game::Game(int width, int height, int fps, std::string title)
{
    assert(GetWindowHandle()); // if assertion triggers: window is already opened
    SetTargetFPS(fps);
    InitWindow(width, height, title.c_str());
}

Game::~Game() noexcept
{
    assert(GetWindowHandle()); // if assertion triggers: window is already closed
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
    ClearBackground(RAYWHITE);
}

void Game::Update()
{

}