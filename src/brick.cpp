#include "brick.h"
#include "common.h"

Brick::Brick(int x, int y)
{
    rect.setSize(QSize(GameParameters::BRICK_WIDTH, GameParameters::BRICK_HEIGHT));
    rect.translate(x, y);
}

QRect Brick::getRect()
{
    return rect;
}
