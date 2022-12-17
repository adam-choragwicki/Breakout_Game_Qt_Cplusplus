#include "ball.h"
#include "common.h"

Ball::Ball(int x, int y)
{
    rect.setSize(QSize(GameParameters::Ball::RADIUS, GameParameters::Ball::RADIUS));
    rect.translate(x, y);
}

QRect Ball::getRect()
{
    return rect;
}
