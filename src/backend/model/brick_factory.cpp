#include "brick_factory.h"
#include "config_prod.h"

BrickFactory::Parameters BrickFactory::generateBrickConstructorParameters(int column, int row)
{
    QColor color = COLORS.at(row % COLORS.size());
    return {column * ConfigProd::Brick::WIDTH, row * ConfigProd::Brick::HEIGHT, color};
}
