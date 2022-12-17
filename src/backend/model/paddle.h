#pragma once

#include "custom_graphics_item.h"

class Paddle : public CustomGraphicsItem
{
public:
    Paddle(int x, int y);
    void reset();

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    void setHorizontalPosition(int x);

private:
    inline static const QColor COLOR = {Qt::blue};

    const int INITIAL_X;
    const int INITIAL_Y;

    const int ROUNDED_RECT_WIDTH_RATIO_PERCENTAGE = 25;
    const int ROUNDED_RECT_HEIGHT_RATIO_PERCENTAGE = 75;
};
