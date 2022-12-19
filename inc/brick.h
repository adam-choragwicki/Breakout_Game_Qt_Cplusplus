#pragma once

#include <QRect>
#include <QColor>

class Brick
{
public:
    Brick(int x, int y, QColor color);
    QRect getRect();

    QColor getColor()
    { return color_; }

private:
    QRect rect;
    const QColor color_;
};
