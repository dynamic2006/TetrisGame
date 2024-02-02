#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
    public:
        static const int ROWS = 20;
        static const int COLS = 10;
        static const int CELLSIZE = 30;
        int values[ROWS][COLS];

        Grid();
        void Initialize();
        void Print();
        void Draw();
        

    private:
        
};