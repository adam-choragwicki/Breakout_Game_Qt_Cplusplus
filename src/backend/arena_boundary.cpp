#include "arena_boundary.h"
#include <QtGui/QPainter>

ArenaBoundary::ArenaBoundary(int x, int y, int width, int height) : CustomGraphicsItem(QRect(x, y, width, height))
{
    displayArenaBoundary_ = false;

    if(displayArenaBoundary_)
    {
        pen_ = QPen(Qt::red, 5);
    }
}

void ArenaBoundary::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    CustomGraphicsItem::paint(painter, option, widget);

    painter->setPen(pen_);
    painter->drawRect(rect_);
}
