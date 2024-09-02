#include "paddle.h"
#include "config_prod.h"
#include <QPainter>

Paddle::Paddle(int x, int y) : CustomGraphicsItem(QRectF(0, 0, ConfigProd::Paddle::WIDTH, ConfigProd::Paddle::HEIGHT)), INITIAL_X(x), INITIAL_Y(y)
{
    setPos(x, y);
}

void Paddle::reset()
{
    setPos(INITIAL_X, INITIAL_Y);
}

void Paddle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    CustomGraphicsItem::paint(painter, option, widget);

    painter->setPen(Qt::black);
    painter->setBrush(COLOR);

    painter->drawRoundedRect(rect_, ROUNDED_RECT_WIDTH_RATIO_PERCENTAGE, ROUNDED_RECT_HEIGHT_RATIO_PERCENTAGE, Qt::RelativeSize);
}

void Paddle::setHorizontalPosition(int x)
{
    setPos(x - rect_.width() / 2, INITIAL_Y);
}
