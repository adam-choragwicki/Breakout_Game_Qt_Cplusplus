#pragma once

#include "common.h"

#include <QRect>

class Ball
{
public:
    Ball(int x, int y);
    void move();

    const QRect& getRect()
    { return rect_; }

    void setHorizontalDirection(HorizontalDirection horizontalDirection)
    { horizontalDirection_ = horizontalDirection; }

    void setVerticalDirection(VerticalDirection verticalDirection)
    { verticalDirection_ = verticalDirection; }

private:
    QRect rect_;

    HorizontalDirection horizontalDirection_;
    VerticalDirection verticalDirection_;
};
