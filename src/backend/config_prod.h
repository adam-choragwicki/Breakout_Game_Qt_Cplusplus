#pragma once

#include <QInternal>
#include <chrono>
//#include "direction.h"
//#include "coordinates.h"
#include <QColor>

namespace ConfigProd
{
    namespace Arena
    {
        const int PRIMARY_SQUARE_SIZE = 40;

        const int PLAYABLE_HORIZONTAL_SQUARES_COUNT = 20;
        const int PLAYABLE_VERTICAL_SQUARES_COUNT = 20;

        const int TOTAL_HORIZONTAL_SQUARES_COUNT_INCLUDING_BOUNDARY_WALLS = PLAYABLE_HORIZONTAL_SQUARES_COUNT + 2;
        const int TOTAL_VERTICAL_SQUARES_COUNT_INCLUDING_BOUNDARY_WALLS = PLAYABLE_VERTICAL_SQUARES_COUNT + 2;

        const int MINIMUM_X = 1;
        const int MINIMUM_Y = 1;
        const int MAXIMUM_X = PLAYABLE_HORIZONTAL_SQUARES_COUNT;
        const int MAXIMUM_Y = PLAYABLE_VERTICAL_SQUARES_COUNT;

        constexpr int TOTAL_FIELDS_COUNT = MAXIMUM_Y * MAXIMUM_X;
    }

    namespace Brick
    {
        const int ROWS_COUNT = 5;
        const int COLUMNS_COUNT = 15;

        const int WIDTH = 50;
        const int HEIGHT = 20;

        const std::vector<QColor> COLORS = {Qt::red, QColor{"orange"}, Qt::green, Qt::yellow, Qt::cyan};
    }

    namespace Arena
    {
        constexpr int WIDTH = Brick::WIDTH * Brick::COLUMNS_COUNT;
        const int HEIGHT = Brick::HEIGHT * 20;

        const int LEFT_EDGE = 0;
        constexpr int RIGHT_EDGE = Brick::WIDTH * Brick::COLUMNS_COUNT;

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
        const int POSITION_Y = Paddle::POSITION_Y - 14;
    }

    namespace Timing
    {
        using namespace std::chrono_literals;
        const auto GAME_TICK_INTERVAL(3ms);
    }

    extern int MOVEMENT_DELAY_MS;
}
