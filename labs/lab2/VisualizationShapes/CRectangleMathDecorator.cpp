#include "CRectangleMathDecorator.h"
#include "CRectangle.h"

float CRectangleMathDecorator::GetArea() const
{
    CRectangle* rectangle = dynamic_cast<CRectangle*>(shape);

    if (rectangle)
    {
        return rectangle->GetSize().x * rectangle->GetSize().y;
    }

    return 0.0;
}

float CRectangleMathDecorator::GetPerimeter() const
{
    CRectangle* rectangle = dynamic_cast<CRectangle*>(shape);

    if (rectangle)
    {
        return TWO * (rectangle->GetSize().x + rectangle->GetSize().y);
    }

    return 0.0;
}