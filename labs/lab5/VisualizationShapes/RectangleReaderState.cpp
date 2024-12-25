#include "RectangleReaderState.h"

std::shared_ptr<IShape> RectangleReaderState::ReadShape(std::istream& iss)
{
    CRectangleFileDecorator rectangle;
    return rectangle.ReadShape(iss);
}
