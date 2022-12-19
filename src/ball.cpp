#include "ball.h"
#include "common.h"

Ball::Ball(int x, int y)
{
    horizontalDirection_ = HorizontalDirection::EAST;
    verticalDirection_ = VerticalDirection::NORTH;

    rect_.setSize(QSize(GameParameters::Ball::RADIUS, GameParameters::Ball::RADIUS));
    rect_.translate(x, y);
}

QRect Ball::getRect()
{
    return rect_;
}

void Ball::move()
{
    rect_.translate(static_cast<int>(horizontalDirection_), static_cast<int>(verticalDirection_));
}
