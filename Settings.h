#include "Vec2.h"

namespace settings
{
    //Window Settings
    inline constexpr int SCREENWIDTH = 800;
    inline constexpr int SCREENHEIGHT = 600;
    inline constexpr int fps = 60;

    //Board Settings
    inline constexpr int cellSize = 23;
    inline constexpr int padding = 2;
    inline constexpr Vec2<int> boardPosition{250, 70};
    inline constexpr Vec2<int> boardWidthHeight{10, 20};
}