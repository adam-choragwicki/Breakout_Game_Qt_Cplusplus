#include "model/brick.h"
#include "common.h"

Brick::Brick(int x, int y, QColor color) : color_(color)
{
    rect_.setSize(QSize(GameParameters::Brick::WIDTH, GameParameters::Brick::HEIGHT));
    rect_.translate(x, y);
}
