#include "ball.h"
#include "common.h"

Ball::Ball(int x, int y)
{
    horizontalDirection = 1;
    verticalDirection = -1;

    rect.setSize(QSize(GameParameters::Ball::RADIUS, GameParameters::Ball::RADIUS));
    rect.translate(x, y);
}

QRect Ball::getRect()
{
    return rect;
}

void Ball::move()
{
    rect.translate(horizontalDirection, verticalDirection);

    if(rect.left() == GameParameters::Arena::LEFT_EDGE)
    {
        horizontalDirection = +1;
    }

    if(rect.right() == GameParameters::Arena::RIGHT_EDGE)
    {
        horizontalDirection = -1;
    }

    if(rect.top() == GameParameters::Arena::TOP_EDGE)
    {
        verticalDirection = +1;
    }

    if(rect.bottom() == GameParameters::Arena::BOTTOM_EDGE)
    {
        verticalDirection = -1;
    }
}
