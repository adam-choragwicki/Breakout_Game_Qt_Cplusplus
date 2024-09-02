#pragma once

#include <set>
#include <memory>
#include "brick.h"

class BricksContainer
{
public:
    BricksContainer();
    ~BricksContainer();

    void reset();

    bool isEmpty();
    [[nodiscard]] std::set<Brick>::const_iterator begin() const;
    [[nodiscard]] std::set<Brick>::const_iterator end() const;
    void removeBrick(const Brick& brick);
    void hideAllBricks();
    void showAllBricks();

private:
    void createBricks();

    std::set<Brick> bricks_;
};
