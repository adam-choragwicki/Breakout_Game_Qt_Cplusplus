#include "movement_vector.h"
#include <QPointF>

MovementVector::MovementVector(HorizontalDirection horizontalDirection, VerticalDirection verticalDirection) : horizontalDirection_(horizontalDirection), verticalDirection_(verticalDirection)
{}

QPointF MovementVector::toQPointF() const
{
    return QPointF(static_cast<int>(horizontalDirection_), static_cast<int>(verticalDirection_));
}

//QString MovementVector::toString() const
//{
//    return QString("Vector: (%1, %2)").arg(horizontalSpeed_).arg(verticalSpeed_);
//}
