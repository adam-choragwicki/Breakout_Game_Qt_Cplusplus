#pragma once

#include "custom_graphics_item.h"
#include "coordinates.h"
#include <QColor>

class Brick : public CustomGraphicsItem
{
public:
    Brick(int x, int y, unsigned int id, QColor color);
    ~Brick() override;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

private:
    const QColor color_;
    const Coordinates coordinates_;
};
