#pragma once

namespace GameParameters
{
    const int ROWS_COUNT = 5;
    const int COLUMNS_COUNT = 15;

    const int GAME_TICK_MS = 3;

    namespace Brick
    {
        const int WIDTH = 50;
        const int HEIGHT = 20;
    }

    namespace Arena
    {
        constexpr int WIDTH = Brick::WIDTH * COLUMNS_COUNT;
        const int HEIGHT = Brick::HEIGHT * 20;

        const int LEFT_EDGE = 0;
        constexpr int RIGHT_EDGE = Brick::WIDTH * COLUMNS_COUNT;

        const int TOP_EDGE = 0;
        const int BOTTOM_EDGE = HEIGHT;
    }

    namespace Paddle
    {
        const int WIDTH = Arena::WIDTH / 10;
        const int HEIGHT = 10;
        const int POSITION_X = Arena::WIDTH / 2 - WIDTH / 2;
        const int POSITION_Y = Arena::HEIGHT * 0.95;
    }

    namespace Ball
    {
        const int RADIUS = 10;
        const int POSITION_X = Paddle::POSITION_X + Paddle::WIDTH / 2;
        const int POSITION_Y = Paddle::POSITION_Y - 5;
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

enum class GameState
{
    STOPPED, RUNNING
};

enum class GameResult
{
    NO_RESULT_YET, WIN, LOSE
};
