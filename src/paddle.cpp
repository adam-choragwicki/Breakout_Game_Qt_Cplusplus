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
    if(rect.left() >= GameParameters::Paddle::MOVE_INCREMENT)
    {
        rect.moveLeft(rect.left() - GameParameters::Paddle::MOVE_INCREMENT);
    }
}

void Paddle::moveRight()
{
    //todo boundaries
    if(rect.right() <= GameParameters::Arena::WIDTH - GameParameters::Paddle::MOVE_INCREMENT)
    {
        rect.moveRight(rect.right() + GameParameters::Paddle::MOVE_INCREMENT);
    }
}
