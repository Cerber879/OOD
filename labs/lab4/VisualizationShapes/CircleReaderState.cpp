#include "CircleReaderState.h"

std::shared_ptr<IShape> CircleReaderState::ReadShape(std::istream& iss)
{
    CCircleFileDecorator circle;
    return circle.ReadShape(iss);
}
