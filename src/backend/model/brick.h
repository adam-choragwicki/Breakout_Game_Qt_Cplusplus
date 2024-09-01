#pragma once

#include "custom_graphics_item.h"
#include <QRect>
#include <QColor>

class Brick : public CustomGraphicsItem
{
public:
    Brick(int x, int y, unsigned int id, QColor color);
    ~Brick() override;

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    //    [[nodiscard]] QRect getRect() const
    //    { return rect_; }

    [[nodiscard]] QColor getColor() const
    { return color_; }

    bool operator<(const Brick& other) const
    {
        return id_ < other.id_;
    }

private:
    const QColor color_;
    const unsigned int id_;
};
