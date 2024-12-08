#include "TriangleWriterState.h"

void TriangleWriterState::WriteShape(std::ostream& os, const std::shared_ptr<IShape>& shape)
{
    CTriangleFileDecorator triangle(shape.get());
    os << triangle.WriteShape(shape);
}