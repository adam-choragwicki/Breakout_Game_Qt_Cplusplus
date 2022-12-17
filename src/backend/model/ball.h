#pragma once

#include "config.h"
#include "direction.h"

#include <QRect>

class Ball
{
public:
    Ball(int x, int y);

    [[nodiscard]] QRect getRect() const
    { return rect_; }

    bool isFallingDown()
    {
        return direction_.getVerticalDirection() == VerticalDirection::SOUTH;
    }

    void move();
    void bounceHorizontally();
    void bounceVertically();

private:
    QRect rect_;
    Direction direction_;
};
