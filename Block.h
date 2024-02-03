#pragma once
#include <raylib.h>
#include <vector>

class Block
{
    public:
        static const int CELLSIZE = 30;

        Block();
        void Rotate();
        void UndoRotate();
        void Draw(int xOffset, int yOffset);
        void Move(int rows, int cols);
        int IsBlockOutside(int gridRows, int gridCols);
        bool AtBottom(int gridRows);

        std::vector<bool> GetShape();
        int GetRowOffset();
        int GetColOffset();
        int GetDimension();
        int GetId();

    protected:
        int id;
        int dimension;
        int rowOffset, colOffset;
        std::vector<bool> shape;
        std::vector<bool> prevShape;

};

class LBlock : public Block
{
    public:
        LBlock(){
            shape = {0,0,1,
                    1,1,1,
                    0,0,0};
            dimension = 3;
            id = 1;
            Move(0,3);
        }

};

class JBlock : public Block
{
    public:
        JBlock(){
            shape = {1,0,0,
                     1,1,1,
                     0,0,0};
            dimension = 3;
            id = 2;
            Move(0,3);
        }

};

class IBlock : public Block
{
    public:
        IBlock(){
            shape = {0,0,0,0,
                     1,1,1,1,
                     0,0,0,0,
                     0,0,0,0};
            dimension = 4;
            id = 3;
            Move(-1,3);
        }

};

class OBlock : public Block
{
    public:
        OBlock(){
            shape = {1,1,
                     1,1};
            dimension = 2;
            id = 4;
            Move(0,4);
        }

};

class SBlock : public Block
{
    public:
        SBlock(){
            shape = {0,1,1,
                     1,1,0,
                     0,0,0};
            dimension = 3;
            id = 5;
            Move(0,3);
        }

};

class TBlock : public Block
{
    public:
        TBlock(){
            shape = {0,1,0,
                     1,1,1,
                     0,0,0};
            dimension = 3;
            id = 6;
            Move(0,3);
        }

};

class ZBlock : public Block
{
    public:
        ZBlock(){
            shape = {1,1,0,
                     0,1,1,
                     0,0,0};
            dimension = 3;
            id = 7;
            Move(0,3);
        }

};