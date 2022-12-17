#pragma once

#include <QRect>

class Paddle
{
public:
    Paddle(int x, int y);
    QRect getRect();

private:
    QRect rect;
};
