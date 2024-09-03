#include "movement_vector.h"
#include <QPointF>

MovementVector::MovementVector(HorizontalDirection horizontalDirection, VerticalDirection verticalDirection) : horizontalDirection_(horizontalDirection), verticalDirection_(verticalDirection)
{}

QPointF MovementVector::toQPointF() const
{
    return QPointF(static_cast<int>(horizontalDirection_), static_cast<int>(verticalDirection_));
}
