#pragma once

#include "brick.h"
#include <memory>

typedef std::map<Coordinates, std::unique_ptr<Brick>> CoordinatesToBricksMapping;

class BricksManager
{
public:
    BricksManager();
    ~BricksManager();

    void reset();

    bool isEmpty();
    [[nodiscard]] CoordinatesToBricksMapping::const_iterator begin() const;
    [[nodiscard]] CoordinatesToBricksMapping::const_iterator end() const;
    void removeBrickAtCoordinates(const Coordinates& coordinates);
    void hideAllBricks();
    void showAllBricks();

    CoordinatesToBricksMapping& getCoordinatesToBricksMapping();

private:
    void createBricks();

    CoordinatesToBricksMapping coordinatesToBricksMapping_;
};
