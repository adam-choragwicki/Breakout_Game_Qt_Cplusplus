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

void Paddle::moveLeft()
{
    //todo boundaries
    if(rect.left() >= 5)
    {
        rect.moveLeft(rect.left() - 5);
    }
}

void Paddle::moveRight()
{
    //todo boundaries
    if(rect.right() <= 235)
    {
        rect.moveRight(rect.right() + 5);
    }
}
