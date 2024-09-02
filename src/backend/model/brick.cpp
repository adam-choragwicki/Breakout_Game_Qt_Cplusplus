#include "brick.h"
#include "config_prod.h"
#include <QPainter>

Brick::Brick(int x, int y, QColor color) : CustomGraphicsItem(QRectF(0, 0, ConfigProd::Brick::WIDTH, ConfigProd::Brick::HEIGHT)), coordinates_(Coordinates{x, y}), color_(color)
{
    setPos(x, y);
}

Brick::~Brick()
{
    //    qDebug() << "Destroying brick at " << coordinates_.toString();
}

void Brick::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    CustomGraphicsItem::paint(painter, option, widget);

    painter->setPen(Qt::black);
    painter->setBrush(color_);
    painter->drawRect(rect_);
}
