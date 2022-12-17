#pragma once

#include <QRect>

class Brick
{
public:
    Brick(int x, int y);
    QRect getRect();

private:
    QRect rect;
};
