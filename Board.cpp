#include "Board.h"
#include "assert.h"

Board::Cell::Cell()
    :
    boardExists(false),
    c(WHITE)
{
}

void Board::Cell::SetColor(Color c_in)
{
    c = c_in;
    boardExists = true;
}

void Board::Cell::Remove()
{
    boardExists = false;
}

Board::Board(int x, int y, int width, int height, int cellSize)
    :
    screenX(x), screenY(y), width(width), height(height), cellSize(cellSize)
{
    assert(width > 0 && height > 0);
    assert(cellSize > 0);
    cells.resize(width*height);
}

void Board::SetCell(int x, int y, Color c)
{
    assert(x >=0 && y >= 0 && x < width && y < height);
    cells[y*width + x].SetColor(c);
}

void Board::DrawCell(int x, int y) const
{
    DrawRectangle()
}
