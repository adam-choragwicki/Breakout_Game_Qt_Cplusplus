#pragma once

#include <QRect>

class Paddle
{
public:
    Paddle(int x, int y);
    QRect getRect();
    void setHorizontalPosition(int x);

private:
    QRect rect;
};
