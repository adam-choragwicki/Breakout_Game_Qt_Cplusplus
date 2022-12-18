#pragma once

#include <QRect>

class Ball
{
public:
    Ball(int x, int y);
    QRect getRect();

    void move();

    void setHorizontalDirection(int horizontalDirection)
    { horizontalDirection_ = horizontalDirection; }

    void setVerticalDirection(int verticalDirection)
    { verticalDirection_ = verticalDirection; }

    [[nodiscard]] int getHorizontalDirection() const
    { return horizontalDirection_; }

    [[nodiscard]] int getVerticalDirection() const
    { return verticalDirection_; }

private:
    QRect rect_;

    int horizontalDirection_;
    int verticalDirection_;
};
