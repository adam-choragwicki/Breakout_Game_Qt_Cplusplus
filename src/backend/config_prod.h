#pragma once

#include <chrono>
#include <QColor>

namespace ConfigProd
{
    namespace Brick
    {
        extern const int WIDTH;
        extern const int HEIGHT;
    }

    namespace Arena
    {
        extern const int ROWS_COUNT;
        extern const int COLUMNS_COUNT;

        const int WIDTH = COLUMNS_COUNT * Brick::WIDTH;
        const int HEIGHT = 30 * Brick::HEIGHT;
    }

    namespace Paddle
    {
        /* Paddle width is 10% of arena width */
        const int WIDTH = 0.1 * Arena::WIDTH;
        const int HEIGHT = 15;
        const int POSITION_X = Arena::WIDTH / 2 - WIDTH / 2;
        const int POSITION_Y = 0.95 * Arena::HEIGHT;
    }

    namespace Ball
    {
        const int RADIUS = 20;
        const int POSITION_X = Paddle::POSITION_X + Paddle::WIDTH / 2;
        const int POSITION_Y = Paddle::POSITION_Y - 14;
        extern const int SPEED_MULTIPLIER;
    }

    extern const int GAME_LOOP_INTERVAL_MS;
    extern const int VIEWPORT_UPDATE_INTERVAL_MS;
    extern const bool GPU_OPTIMIZATION;
}
