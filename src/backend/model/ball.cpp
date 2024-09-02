#include "ball.h"
#include "config_prod.h"
#include <QPainter>

Ball::Ball(int x, int y) : CustomGraphicsItem(x, y), INITIAL_X(x), INITIAL_Y(y), INITIAL_MOVEMENT_VECTOR(HorizontalDirection::EAST, VerticalDirection::NORTH), movementVector_(INITIAL_MOVEMENT_VECTOR)
{
    rect_.setSize(QSize(ConfigProd::Ball::RADIUS, ConfigProd::Ball::RADIUS));
}

void Ball::reset()
{
    rect_.moveTo(INITIAL_X, INITIAL_Y);
    movementVector_ = INITIAL_MOVEMENT_VECTOR;
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
    rect_.translate(static_cast<int>(movementVector_.getHorizontalDirection()), static_cast<int>(movementVector_.getVerticalDirection()));
}

void Ball::setHorizontalPosition(int x)
{
    rect_.moveCenter(QPointF(x, ConfigProd::Ball::POSITION_Y));
}

void Ball::bounceHorizontally()
{
    if(movementVector_.getVerticalDirection() == VerticalDirection::NORTH)
    {
        movementVector_.setVerticalDirection(VerticalDirection::SOUTH);
    }
    else
    {
        movementVector_.setVerticalDirection(VerticalDirection::NORTH);
    }
}

void Ball::bounceVertically()
{
    if(movementVector_.getHorizontalDirection() == HorizontalDirection::EAST)
    {
        movementVector_.setHorizontalDirection(HorizontalDirection::WEST);
    }
    else
    {
        movementVector_.setHorizontalDirection(HorizontalDirection::EAST);
    }
}

bool Ball::isFallingDown()
{
    return movementVector_.getVerticalDirection() == VerticalDirection::SOUTH;
}
