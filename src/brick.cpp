#include "brick.h"
#include "common.h"

Brick::Brick(int x, int y)
{
    rect.setSize(QSize(GameParameters::Brick::WIDTH, GameParameters::Brick::HEIGHT));
    rect.translate(x, y);
}

QRect Brick::getRect()
{
    return rect;
}
