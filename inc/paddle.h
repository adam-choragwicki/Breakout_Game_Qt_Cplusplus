#pragma once

#include <QRect>

class Paddle
{
public:
    Paddle(int x, int y);
    QRect getRect();
    void moveLeft();
    void moveRight();

private:
    QRect rect;
};
