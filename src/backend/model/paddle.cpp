#include "paddle.h"
#include "config_prod.h"
#include <QPainter>

Paddle::Paddle(int x, int y) : CustomGraphicsItem(x, y), INITIAL_X(x), INITIAL_Y(y)
{
    rect_.setSize(QSize(ConfigProd::Paddle::WIDTH, ConfigProd::Paddle::HEIGHT));
}

void Paddle::reset()
{
    rect_.moveTo(INITIAL_X, INITIAL_Y);
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
    rect_.moveCenter(QPointF(x, ConfigProd::Paddle::POSITION_Y));
}
