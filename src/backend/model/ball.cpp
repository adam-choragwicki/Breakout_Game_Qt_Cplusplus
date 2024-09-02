#include "ball.h"
#include "config_prod.h"
#include <QPainter>

Ball::Ball(int x, int y) :
        CustomGraphicsItem(QRectF(0, 0, ConfigProd::Ball::RADIUS, ConfigProd::Ball::RADIUS)), INITIAL_X(x), INITIAL_Y(y), INITIAL_MOVEMENT_VECTOR(HorizontalDirection::EAST, VerticalDirection::NORTH), movementVector_(INITIAL_MOVEMENT_VECTOR)
{
    setPos(x, y);
}

void Ball::reset()
{
    setPos(INITIAL_X, INITIAL_Y);

    //    rect_.moveTo(INITIAL_X, INITIAL_Y);
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
    //    qDebug() << "Move by: " << static_cast<int>(movementVector_.getHorizontalDirection()) << "," << static_cast<int>(movementVector_.getVerticalDirection());
    moveBy(static_cast<int>(movementVector_.getHorizontalDirection()), static_cast<int>(movementVector_.getVerticalDirection()));
}

void Ball::setHorizontalPosition(int x)
{
    setPos(QPointF(x - rect_.width() / 2, ConfigProd::Ball::POSITION_Y));
    //setPos(QPointF(x + rect_.width() / 2, ConfigProd::Ball::POSITION_Y));

    //    rect_.moveCenter(QPointF(x, ConfigProd::Ball::POSITION_Y));
    //    rect_.moveCenter(QPointF(x, ConfigProd::Ball::POSITION_Y));
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
