#pragma once

#include <QRect>

class Ball
{
public:
    Ball(int x, int y);
    QRect getRect();

    void move();

private:
    QRect rect;

    int horizontalDirection;
    int verticalDirection;
};
