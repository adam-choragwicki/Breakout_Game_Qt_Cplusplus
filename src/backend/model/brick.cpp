#include "brick.h"
#include "config_prod.h"
#include <QPainter>

Brick::Brick(int x, int y, unsigned int id, QColor color) : CustomGraphicsItem(x, y), coordinates_(Coordinates{x, y}), color_(color)
{
    qDebug() << "Creating brick at " << coordinates_.toString();
    rect_.setSize(QSize(ConfigProd::Brick::WIDTH, ConfigProd::Brick::HEIGHT));
}

Brick::~Brick()
{
    qDebug() << "Destroying brick at " << coordinates_.toString();
}

void Brick::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    CustomGraphicsItem::paint(painter, option, widget);

    painter->setPen(Qt::black);
    painter->setBrush(color_);
    painter->drawRect(rect_);
}
