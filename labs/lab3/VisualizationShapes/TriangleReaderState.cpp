#include "TriangleReaderState.h"

std::shared_ptr<IShape> TriangleReaderState::ReadShape(std::istream& iss)
{
    CTriangleFileDecorator triangle;
    return triangle.ReadShape(iss);
}
