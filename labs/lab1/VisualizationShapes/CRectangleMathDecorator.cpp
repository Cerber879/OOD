#include "CRectangleMathDecorator.h"
#include "CRectangle.h"

std::string CRectangleMathDecorator::GetType() const
{
    return RECTANGLE;
}

double CRectangleMathDecorator::GetArea() const
{
    CRectangle* rectangle = dynamic_cast<CRectangle*>(shape);

    if (rectangle)
    {
        return rectangle->GetSize().x * rectangle->GetSize().y;
    }

    return 0.0;
}

double CRectangleMathDecorator::GetPerimeter() const
{
    CRectangle* rectangle = dynamic_cast<CRectangle*>(shape);

    if (rectangle)
    {
        return TWO * (rectangle->GetSize().x + rectangle->GetSize().y);
    }

    return 0.0;
}