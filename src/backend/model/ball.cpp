#include "ball.h"
#include "config.h"

Ball::Ball(int x, int y) : direction_(HorizontalDirection::EAST, VerticalDirection::NORTH)
{
    rect_.setSize(QSize(Config::Ball::RADIUS, Config::Ball::RADIUS));
    rect_.translate(x, y);
}

void Ball::move()
{
    rect_.translate(static_cast<int>(direction_.getHorizontalDirection()), static_cast<int>(direction_.getVerticalDirection()));
}

void Ball::bounceHorizontally()
{
    if(direction_.getVerticalDirection() == VerticalDirection::NORTH)
    {
        direction_.setVerticalDirection(VerticalDirection::SOUTH);
    }
    else
    {
        direction_.setVerticalDirection(VerticalDirection::NORTH);
    }
}

void Ball::bounceVertically()
{
    if(direction_.getHorizontalDirection() == HorizontalDirection::EAST)
    {
        direction_.setHorizontalDirection(HorizontalDirection::WEST);
    }
    else
    {
        direction_.setHorizontalDirection(HorizontalDirection::EAST);
    }
}
