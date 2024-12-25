#include "RectangleWriterState.h"

void RectangleWriterState::WriteShape(std::ostream& os, const std::shared_ptr<IShape>& shape)
{
    CRectangleFileDecorator rectangle(shape.get());
    os << rectangle.WriteShape(shape);
}