#pragma once

#include "custom_graphics_item.h"
#include <QRect>

class Paddle : public CustomGraphicsItem
{
public:
    Paddle(int x, int y);

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    [[nodiscard]] QRect getRect() const
    { return rect_; }

    void setHorizontalPosition(int x);

private:
    inline static const QColor COLOR = {Qt::blue};

    QRect rect_;

    const int ROUNDED_RECT_WIDTH_RATIO_PERCENTAGE = 25;
    const int ROUNDED_RECT_HEIGHT_RATIO_PERCENTAGE = 75;
};
