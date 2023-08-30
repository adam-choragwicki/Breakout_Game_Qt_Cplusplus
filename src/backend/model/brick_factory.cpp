#include "brick_factory.h"
#include "config.h"

BrickFactory::Parameters BrickFactory::generateBrickConstructorParameters(int column, int row)
{
    QColor color = Config::Brick::COLORS.at(row % Config::Brick::COLORS.size());
    ++count_;

    return {column * Config::Brick::WIDTH, row * Config::Brick::HEIGHT, count_, color};
}
