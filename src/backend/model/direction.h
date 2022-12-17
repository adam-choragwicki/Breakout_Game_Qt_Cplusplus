#pragma once

enum class VerticalDirection
{
    NORTH = -1, SOUTH = +1
};

enum class HorizontalDirection
{
    WEST = -1, EAST = +1
};

class Direction
{
public:
    Direction(HorizontalDirection horizontalDirection, VerticalDirection verticalDirection);
    [[nodiscard]] HorizontalDirection getHorizontalDirection() const;
    void setHorizontalDirection(HorizontalDirection horizontalDirection);
    [[nodiscard]] VerticalDirection getVerticalDirection() const;
    void setVerticalDirection(VerticalDirection verticalDirection);

private:
    HorizontalDirection horizontalDirection_;
    VerticalDirection verticalDirection_;
};
