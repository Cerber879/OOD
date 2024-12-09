#include "CircleWriterState.h"

void CircleWriterState::WriteShape(std::ostream& os, const std::shared_ptr<IShape>& shape)
{
    CCircleFileDecorator circle(shape.get());
    os << circle.WriteShape(shape);
}