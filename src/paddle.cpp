#include "paddle.h"
#include "common.h"

Paddle::Paddle(int x, int y)
{
    rect.setSize(QSize(GameParameters::Paddle::WIDTH, GameParameters::Paddle::HEIGHT));
    rect.translate(x, y);
}

QRect Paddle::getRect()
{
    return rect;
}

void Paddle::setHorizontalPosition(int x)
{
    rect.moveCenter({x, GameParameters::Paddle::POSITION_Y});
}
