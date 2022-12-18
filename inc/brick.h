#pragma once

#include <QRect>

class Brick
{
public:
    Brick(int x, int y);
    QRect getRect();

    [[nodiscard]] bool isDestroyed() const
    { return destroyed_; }

    void setDestroyed(bool destroyed)
    { destroyed_ = destroyed; }

private:
    QRect rect;
    bool destroyed_{};
};
