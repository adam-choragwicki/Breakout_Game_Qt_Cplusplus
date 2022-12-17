#pragma once

namespace GameParameters
{
    const int ROWS_COUNT = 5;
    const int COLUMNS_COUNT = 6;
    constexpr int BRICKS_COUNT = ROWS_COUNT * COLUMNS_COUNT;

    namespace Brick
    {
        const int WIDTH = 40;
        const int HEIGHT = 10;
    }

    namespace Paddle
    {
        const int WIDTH = 60;
        const int HEIGHT = 5;
    }
}
