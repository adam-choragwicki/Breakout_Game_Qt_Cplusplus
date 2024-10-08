#include "ball.h"
#include "config_prod.h"
#include <QPainter>

Ball::Ball(int x, int y) :
        CustomGraphicsItem(QRectF(0, 0, ConfigProd::Ball::RADIUS, ConfigProd::Ball::RADIUS)), INITIAL_X(x), INITIAL_Y(y), INITIAL_MOVEMENT_VECTOR(HorizontalDirection::EAST, VerticalDirection::NORTH), movementVector_(INITIAL_MOVEMENT_VECTOR)
{
    setPos(x, y);
    movementVector_ = INITIAL_MOVEMENT_VECTOR;

    setFlag(QGraphicsItem::ItemIsMovable, true);
    setFlag(QGraphicsItem::ItemClipsToShape, false);
    setFlag(QGraphicsItem::ItemClipsChildrenToShape, false);
}

void Ball::reset()
{
    setPos(INITIAL_X, INITIAL_Y);
    movementVector_ = INITIAL_MOVEMENT_VECTOR;
}

void Ball::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    CustomGraphicsItem::paint(painter, option, widget);

    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(Qt::NoPen);
    painter->setBrush(COLOR);
    painter->drawEllipse(rect_);
}

void Ball::move()
{
    //qDebug() << "Move by: " << static_cast<int>(movementVector_.getHorizontalDirection()) << "," << static_cast<int>(movementVector_.getVerticalDirection());
    moveBy(ConfigProd::Ball::SPEED_MULTIPLIER * static_cast<int>(movementVector_.getHorizontalDirection()), ConfigProd::Ball::SPEED_MULTIPLIER * static_cast<int>(movementVector_.getVerticalDirection()));
}

void Ball::setHorizontalPosition(int x)
{
    setPos(x - rect_.width() / 2, INITIAL_Y);
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
