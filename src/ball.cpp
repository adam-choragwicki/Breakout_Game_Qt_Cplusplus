#include "ball.h"
#include "common.h"

Ball::Ball(int x, int y)
{
    horizontalDirection_ = 1;
    verticalDirection_ = -1;

    rect_.setSize(QSize(GameParameters::Ball::RADIUS, GameParameters::Ball::RADIUS));
    rect_.translate(x, y);
}

QRect Ball::getRect()
{
    return rect_;
}

void Ball::move()
{
    rect_.translate(horizontalDirection_, verticalDirection_);
}
