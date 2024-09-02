#include "bricks_container.h"
#include "brick_factory.h"
#include "config_prod.h"

BricksContainer::BricksContainer()
{
    qDebug() << "Creating bricks container";
}

BricksContainer::~BricksContainer()
{
    qDebug() << "Destroying bricks container";
}

void BricksContainer::reset()
{
    bricks_.clear();
    createBricks();
}

void BricksContainer::createBricks()
{
    BrickFactory brickFactory;

    for(int row = 0; row < ConfigProd::Arena::ROWS_COUNT; row++)
    {
        for(int column = 0; column < ConfigProd::Arena::COLUMNS_COUNT; column++)
        {
            BrickFactory::Parameters parameters = brickFactory.generateBrickConstructorParameters(column, row);

            const auto&[_, inserted] = bricks_.emplace(parameters.x_, parameters.y_, parameters.id_, parameters.color_);

            if(!inserted)
            {
                throw std::runtime_error("Error, duplicate brick");
            }
        }
    }
}

bool BricksContainer::isEmpty()
{
    return bricks_.empty();
}

std::set<Brick>::const_iterator BricksContainer::begin() const
{
    return bricks_.begin();
}

std::set<Brick>::const_iterator BricksContainer::end() const
{
    return bricks_.end();
}

void BricksContainer::removeBrick(const Brick& brick)
{
    unsigned int elementsErased = bricks_.erase(brick);

    if(elementsErased == 0)
    {
        throw std::runtime_error("Error, remove brick operation did not remove any bricks");
    }
}

void BricksContainer::hideAllBricks()
{
    for(const Brick& brick : bricks_)
    {
        const_cast<Brick&>(brick).hide();
    }
}

void BricksContainer::showAllBricks()
{
    for(const Brick& brick : bricks_)
    {
        const_cast<Brick&>(brick).show();
    }
}
