#pragma once

#include <QRect>
#include <QColor>

class Brick
{
public:
    Brick(int x, int y, QColor color);

    QRect getRect()
    {return rect_;}

    QColor getColor()
    { return color_; }

private:
    QRect rect_;
    const QColor color_;
};
