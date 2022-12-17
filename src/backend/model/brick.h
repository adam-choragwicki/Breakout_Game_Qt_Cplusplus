#pragma once

#include <QRect>
#include <QColor>

class Brick
{
public:
    Brick(int x, int y, unsigned int id, QColor color);

    [[nodiscard]] QRect getRect() const
    { return rect_; }

    [[nodiscard]] QColor getColor() const
    { return color_; }

    bool operator<(const Brick& other) const
    {
        return id_ < other.id_;
    }

private:
    QRect rect_;
    const QColor color_;
    const unsigned int id_;
};
