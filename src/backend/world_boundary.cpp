#include "world_boundary.h"
#include <QtGui/QPainter>

WorldBoundary::WorldBoundary(int x, int y, int width, int height) : CustomGraphicsItem(QRect(x, y, width, height))
{
    displayWorldBoundary_ = true;

    if(displayWorldBoundary_)
    {
        pen_ = QPen(Qt::red, 20);
    }

    //drawRect_ = true;
}

void WorldBoundary::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    CustomGraphicsItem::paint(painter, option, widget);

    painter->setPen(pen_);
    painter->drawRect(rect_);
}
