#pragma once

namespace GameParameters
{
    const int ROWS_COUNT = 5;
    const int COLUMNS_COUNT = 6;
    constexpr int BRICKS_COUNT = ROWS_COUNT * COLUMNS_COUNT;

    const int BALL_DELAY_MS = 10;

    namespace Brick
    {
        const int WIDTH = 40;
        const int HEIGHT = 10;
    }

    namespace Paddle
    {
        const int WIDTH = 60;
        const int HEIGHT = 3;
        const int ELEVATION = 130;
    }

    namespace Ball
    {
        const int RADIUS = 5;
        const int STARTING_ELEVATION = Paddle::ELEVATION - 5;
    }

    namespace Arena
    {
        constexpr int WIDTH = Brick::WIDTH * COLUMNS_COUNT;
        const int HEIGHT = 150;

        const int LEFT_EDGE = 0;
        constexpr int RIGHT_EDGE = Brick::WIDTH * COLUMNS_COUNT;

        const int TOP_EDGE = 0;
        const int BOTTOM_EDGE = HEIGHT;
    }
}

enum class VerticalDirection
{
    NORTH = -1, SOUTH = +1
};

enum class HorizontalDirection
{
    WEST = -1, EAST = +1
};
