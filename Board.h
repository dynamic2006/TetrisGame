#include "raylib.h"
#include <vector>

class Board
{

private:
    class Cell
    {
        public:
        Cell();
        void SetColor(Color c_in);
        void Remove();

        private:
        bool boardExists;
        Color c;

    };

public:
    Board(int x, int y, int width, int height, int cellSize);
    void SetCell(int x, int y, Color c);
    void DrawCell(int x, int y) const;
private:
    std::vector<Cell> cells;
    const int width;
    const int height;
    const int cellSize;
    int screenX, screenY;
};