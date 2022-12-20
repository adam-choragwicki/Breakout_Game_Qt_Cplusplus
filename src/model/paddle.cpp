#include "model/paddle.h"
#include "common.h"

Paddle::Paddle(int x, int y)
{
    rect_.setSize(QSize(GameParameters::Paddle::WIDTH, GameParameters::Paddle::HEIGHT));
    rect_.translate(x, y);
}

void Paddle::setHorizontalPosition(int x)
{
    rect_.moveCenter({x, GameParameters::Paddle::POSITION_Y});
}
