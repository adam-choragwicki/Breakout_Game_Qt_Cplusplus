#pragma once

#include "custom_graphics_item.h"
#include "config.h"
#include "direction.h"

#include <QRect>

class Ball : public CustomGraphicsItem
{
public:
    Ball(int x, int y);

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    bool isFallingDown()
    {
        return direction_.getVerticalDirection() == VerticalDirection::SOUTH;
    }

    void move();
    void bounceHorizontally();
    void bounceVertically();

private:
    inline static const QColor COLOR = {Qt::white};

    Direction direction_;
};
