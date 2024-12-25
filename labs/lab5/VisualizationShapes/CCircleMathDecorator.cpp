#include "CCircleMathDecorator.h"
#include "CCircle.h"

float CCircleMathDecorator::GetArea() const
{
    CCircle* circle = dynamic_cast<CCircle*>(shape);

    if (circle)
    {
        return Constants::MathConstant::PI * circle->GetRadius() * circle->GetRadius();
    }

    return 0.0;
}

float CCircleMathDecorator::GetPerimeter() const
{
    CCircle* circle = dynamic_cast<CCircle*>(shape);

    if (circle)
    {
        return Constants::Number::TWO * Constants::MathConstant::PI * circle->GetRadius();
    }

    return 0.0;
}