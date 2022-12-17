#include "brick.h"
#include "config.h"

Brick::Brick(int x, int y, unsigned int id, QColor color) : id_(id), color_(color)
{
    rect_.setSize(QSize(Config::Brick::WIDTH, Config::Brick::HEIGHT));
    rect_.translate(x, y);
}
