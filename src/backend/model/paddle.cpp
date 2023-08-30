#include "paddle.h"
#include "config.h"

Paddle::Paddle(int x, int y)
{
    rect_.setSize(QSize(Config::Paddle::WIDTH, Config::Paddle::HEIGHT));
    rect_.translate(x, y);
}

void Paddle::setHorizontalPosition(int x)
{
    rect_.moveCenter({x, Config::Paddle::POSITION_Y});
}
