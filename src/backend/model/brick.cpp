#include "brick.h"
#include "config.h"
#include <QPainter>

Brick::Brick(int x, int y, unsigned int id, QColor color) : CustomGraphicsItem(x, y), id_(id), color_(color)
{
    qDebug() << "Creating brick " << id_ << ":" << x << " , " << y;;
    rect_.setSize(QSize(Config::Brick::WIDTH, Config::Brick::HEIGHT));
}

Brick::~Brick()
{
    qDebug() << "Destroying brick " << id_;
}

void Brick::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    CustomGraphicsItem::paint(painter, option, widget);

    painter->setPen(Qt::black);
    painter->setBrush(color_);
    painter->drawRect(rect_);
}
