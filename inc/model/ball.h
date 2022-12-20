#pragma once

#include "common.h"

#include <QRect>

class Ball
{
public:
    Ball(int x, int y);
    void move();

    QRect getRect()
    { return rect_; }

    void setHorizontalDirection(HorizontalDirection horizontalDirection)
    { horizontalDirection_ = horizontalDirection; }

    void setVerticalDirection(VerticalDirection verticalDirection)
    { verticalDirection_ = verticalDirection; }

    [[nodiscard]] HorizontalDirection getHorizontalDirection() const
    { return horizontalDirection_; }

    [[nodiscard]] VerticalDirection getVerticalDirection() const
    { return verticalDirection_; }

private:
    QRect rect_;

    HorizontalDirection horizontalDirection_;
    VerticalDirection verticalDirection_;
};
