#include "paddle.h"
#include "config.h"
#include <QPainter>

Paddle::Paddle(int x, int y) : CustomGraphicsItem(x, y)
{
    rect_.setSize(QSize(Config::Paddle::WIDTH, Config::Paddle::HEIGHT));
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
    rect_.moveCenter(QPointF(x, Config::Paddle::POSITION_Y));
}
