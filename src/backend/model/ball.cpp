#include "ball.h"
#include "config_prod.h"
#include <QPainter>

Ball::Ball(int x, int y) : CustomGraphicsItem(x, y), direction_(HorizontalDirection::EAST, VerticalDirection::NORTH)
{
    rect_.setSize(QSize(ConfigProd::Ball::RADIUS, ConfigProd::Ball::RADIUS));
}

void Ball::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    CustomGraphicsItem::paint(painter, option, widget);

    painter->setPen(Qt::NoPen);
    painter->setBrush(COLOR);
    painter->drawEllipse(rect_);
}

void Ball::move()
{
    rect_.translate(static_cast<int>(direction_.getHorizontalDirection()), static_cast<int>(direction_.getVerticalDirection()));
}

void Ball::setHorizontalPosition(int x)
{
    rect_.moveCenter(QPointF(x, ConfigProd::Ball::POSITION_Y));
}

void Ball::bounceHorizontally()
{
    if(direction_.getVerticalDirection() == VerticalDirection::NORTH)
    {
        direction_.setVerticalDirection(VerticalDirection::SOUTH);
    }
    else
    {
        direction_.setVerticalDirection(VerticalDirection::NORTH);
    }
}

void Ball::bounceVertically()
{
    if(direction_.getHorizontalDirection() == HorizontalDirection::EAST)
    {
        direction_.setHorizontalDirection(HorizontalDirection::WEST);
    }
    else
    {
        direction_.setHorizontalDirection(HorizontalDirection::EAST);
    }
}

bool Ball::isFallingDown()
{
    return direction_.getVerticalDirection() == VerticalDirection::SOUTH;
}
