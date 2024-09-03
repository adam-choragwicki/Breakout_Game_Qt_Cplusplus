#pragma once

class QString;
class QPointF;

enum class HorizontalDirection
{
    WEST = -1, EAST = +1
};

enum class VerticalDirection
{
    NORTH = -1, SOUTH = +1
};

class MovementVector
{
public:
    MovementVector(HorizontalDirection horizontalDirection, VerticalDirection verticalDirection);

    [[nodiscard]] HorizontalDirection getHorizontalDirection() const
    { return horizontalDirection_; }

    [[nodiscard]] VerticalDirection getVerticalDirection() const
    { return verticalDirection_; }

    void setHorizontalDirection(HorizontalDirection horizontalDirection)
    { horizontalDirection_ = horizontalDirection; }

    void setVerticalDirection(VerticalDirection verticalDirection)
    { verticalDirection_ = verticalDirection; }

    //    [[nodiscard]] QString toString() const;
        [[nodiscard]] QPointF toQPointF() const;

private:
    HorizontalDirection horizontalDirection_{};
    VerticalDirection verticalDirection_{};
};
