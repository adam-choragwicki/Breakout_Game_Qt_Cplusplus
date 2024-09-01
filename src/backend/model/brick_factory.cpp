#include "brick_factory.h"
#include "config_prod.h"

BrickFactory::Parameters BrickFactory::generateBrickConstructorParameters(int column, int row)
{
    QColor color = ConfigProd::Brick::COLORS.at(row % ConfigProd::Brick::COLORS.size());
    ++count_;

    return {column * ConfigProd::Brick::WIDTH, row * ConfigProd::Brick::HEIGHT, count_, color};
}
