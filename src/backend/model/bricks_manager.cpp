#include "bricks_manager.h"
#include "brick_factory.h"
#include "config_prod.h"

BricksManager::BricksManager()
{
    qDebug() << "Creating bricks container";
}

BricksManager::~BricksManager()
{
    qDebug() << "Destroying bricks container";
}

void BricksManager::reset()
{
    bricks_.clear();
    createBricks();
}

void BricksManager::createBricks()
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

bool BricksManager::isEmpty()
{
    return bricks_.empty();
}

std::set<Brick>::const_iterator BricksManager::begin() const
{
    return bricks_.begin();
}

std::set<Brick>::const_iterator BricksManager::end() const
{
    return bricks_.end();
}

void BricksManager::removeBrick(const Brick& brick)
{
    unsigned int elementsErased = bricks_.erase(brick);

    if(elementsErased == 0)
    {
        throw std::runtime_error("Error, remove brick operation did not remove any bricks");
    }
}

void BricksManager::hideAllBricks()
{
    for(const Brick& brick : bricks_)
    {
        const_cast<Brick&>(brick).hide();
    }
}

void BricksManager::showAllBricks()
{
    for(const Brick& brick : bricks_)
    {
        const_cast<Brick&>(brick).show();
    }
}
