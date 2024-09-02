#include "bricks_manager.h"
#include "brick_factory.h"
#include "config_prod.h"
#include "coordinates.h"

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
    coordinatesToBricksMapping_.clear();
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

            const auto&[_, inserted] = coordinatesToBricksMapping_.insert_or_assign(Coordinates(row, column), std::make_unique<Brick>(parameters.x_, parameters.y_, parameters.id_, parameters.color_));

            if(!inserted)
            {
                throw std::runtime_error("Error, duplicate brick");
            }
        }
    }
}

bool BricksManager::isEmpty()
{
    return coordinatesToBricksMapping_.empty();
}

CoordinatesToBricksMapping::const_iterator BricksManager::begin() const
{
    return coordinatesToBricksMapping_.begin();
}

CoordinatesToBricksMapping::const_iterator BricksManager::end() const
{
    return coordinatesToBricksMapping_.end();
}

void BricksManager::removeBrickAtCoordinates(const Coordinates& coordinates)
{
    unsigned int elementsErased = coordinatesToBricksMapping_.erase(coordinates);

    if(elementsErased == 0)
    {
        throw std::runtime_error("Error, remove brick operation did not remove any bricks");
    }
}

void BricksManager::hideAllBricks()
{
    for(const auto&[_, brick] : coordinatesToBricksMapping_)
    {
        brick->hide();
    }
}

void BricksManager::showAllBricks()
{
    for(const auto&[_, brick] : coordinatesToBricksMapping_)
    {
        brick->show();
    }
}

CoordinatesToBricksMapping& BricksManager::getCoordinatesToBricksMapping()
{
    return coordinatesToBricksMapping_;
}
