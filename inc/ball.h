#pragma once

#include <QRect>

class Ball
{
public:
    Ball(int x, int y);
    QRect getRect();

private:
    QRect rect;
};
