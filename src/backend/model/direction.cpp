#include "direction.h"

Direction::Direction(HorizontalDirection horizontalDirection, VerticalDirection verticalDirection)
{
    horizontalDirection_ = horizontalDirection;
    verticalDirection_ = verticalDirection;
}

[[nodiscard]] HorizontalDirection Direction::getHorizontalDirection() const
{
    return horizontalDirection_;
}

void Direction::setHorizontalDirection(HorizontalDirection horizontalDirection)
{
    horizontalDirection_ = horizontalDirection;
}

[[nodiscard]] VerticalDirection Direction::getVerticalDirection() const
{
    return verticalDirection_;
}

void Direction::setVerticalDirection(VerticalDirection verticalDirection)
{
    verticalDirection_ = verticalDirection;
}
