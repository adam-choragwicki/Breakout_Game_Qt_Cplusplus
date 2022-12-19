#pragma once

#include <QRect>
#include <QColor>

class Brick
{
public:
    Brick(int x, int y, QColor color);
    QRect getRect();

    [[nodiscard]] bool isDestroyed() const
    { return destroyed_; }

    void setDestroyed(bool destroyed)
    { destroyed_ = destroyed; }

    QColor getColor()
    { return color_; }

private:
    QRect rect;
    const QColor color_;
    bool destroyed_{};
};
