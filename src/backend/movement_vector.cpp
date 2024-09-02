#include "movement_vector.h"

MovementVector::MovementVector(HorizontalDirection horizontalDirection, VerticalDirection verticalDirection) : horizontalDirection_(horizontalDirection), verticalDirection_(verticalDirection)
{}

//QPointF MovementVector::toQPointF() const
//{
//    return {horizontalSpeed_, verticalSpeed_};
//}

//QString MovementVector::toString() const
//{
//    return QString("Vector: (%1, %2)").arg(horizontalSpeed_).arg(verticalSpeed_);
//}
