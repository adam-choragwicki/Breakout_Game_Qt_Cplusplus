#pragma once

#include "custom_graphics_item.h"
#include "direction.h"

class Ball : public CustomGraphicsItem
{
public:
    Ball(int x, int y);
    void reset();

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    void setHorizontalPosition(int x);

    bool isFallingDown();

    void move();
    void bounceHorizontally();
    void bounceVertically();

private:
    inline static const QColor COLOR = {Qt::white};

    const int INITIAL_X;
    const int INITIAL_Y;
    const Direction INITIAL_DIRECTION;

    Direction direction_;
};
