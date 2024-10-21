#include "CCircleMathDecorator.h"
#include "CCircle.h"

std::string CCircleMathDecorator::GetType() const
{
    return CIRCLE;
}

double CCircleMathDecorator::GetArea() const
{
    CCircle* circle = dynamic_cast<CCircle*>(shape);

    if (circle)
    {
        return PI * circle->GetRadius() * circle->GetRadius();
    }

    return 0.0;
}

double CCircleMathDecorator::GetPerimeter() const
{
    CCircle* circle = dynamic_cast<CCircle*>(shape);

    if (circle)
    {
        return TWO * PI * circle->GetRadius();
    }

    return 0.0;
}