#include "Board.h"
#include <assert.h>
Board::Cell::Cell()
    :
    bExists(false),
    c(WHITE)
{
}

void Board::Cell::SetColor(Color c_in)
{
    c = c_in;
    bExists = true;
}

void Board::Cell::Remove()
{
    bExists = false;
}

Color Board::Cell::GetColor() const
{
    return c;
}

Board::Board(Vec2<int> screenPos, Vec2<int> widthHeight, int cellSize, int padding)
    :
    screenPos(screenPos),
    width(widthHeight.GetX()),
    height(widthHeight.GetY()),
    cellSize(cellSize),
    padding(padding)
{
    assert(width > 0 && height > 0);
    assert(cellSize > 0);
    cells.resize(width*height);
}

void Board::SetCell(Vec2<int> pos, Color c)
{
    assert(pos.GetX() >= 0 && pos.GetY() >= 0 && pos.GetX() < width && pos.GetY() < height);
    cells[pos.GetY() * width + pos.GetX()].SetColor(c);
}

void Board::DrawCell(Vec2<int> pos) const
{
    assert(pos.GetX() >= 0 && pos.GetX() < width && pos.GetY() >= 0 && pos.GetY() < height);
    Color c = cells[pos.GetY()*width + pos.GetX()].GetColor();
    Vec2<int> topLeft = screenPos + padding + (pos * cellSize);

    raycpp::DrawRectangle(topLeft, Vec2<int>{cellSize, cellSize} - padding, c);

}

void Board::Draw() const
{
    for(int iy = 0; iy < height; iy++){
        for(int ix = 0; ix < width; ix++){
            DrawCell({ix, iy});
        }
    }
}
