#pragma once

#include <set>
#include <memory>
#include "brick.h"

class BricksContainer
{
public:
    BricksContainer();

    bool isEmpty();
    [[nodiscard]] std::set<Brick>::const_iterator begin() const;
    [[nodiscard]] std::set<Brick>::const_iterator end() const;
    void removeBrick(const Brick& brick);

private:
    std::set<Brick> bricks_;
};
