#pragma once

#include <QRect>

class Paddle
{
public:
    Paddle(int x, int y);

    [[nodiscard]] QRect getRect() const
    { return rect_; }

    void setHorizontalPosition(int x);

private:
    QRect rect_;
};
