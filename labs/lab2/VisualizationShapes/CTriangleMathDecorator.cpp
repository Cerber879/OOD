#include "CTriangleMathDecorator.h"
#include "CTriangle.h"

float CTriangleMathDecorator::GetArea() const
{
    CTriangle* triangle = dynamic_cast<CTriangle*>(shape);

    float firstSize = triangle->GetLengthSide(triangle->GetPoint(0), triangle->GetPoint(1));
    float secondSize = triangle->GetLengthSide(triangle->GetPoint(1), triangle->GetPoint(2));
    float thirdSize = triangle->GetLengthSide(triangle->GetPoint(2), triangle->GetPoint(0));

    if (triangle)
    {
        float s = (triangle->GetSize(0, 1) + triangle->GetSize(1, 2) + triangle->GetSize(2, 0)) / TWO;

        return std::sqrt(s * (s - triangle->GetSize(0, 1)) * (s - triangle->GetSize(1, 2)) * (s - triangle->GetSize(2, 0)));
    }

    return 0.0;
}

float CTriangleMathDecorator::GetPerimeter() const
{
    CTriangle* triangle = dynamic_cast<CTriangle*>(shape);

    if (triangle)
    {
        return triangle->GetSize(0, 1) + triangle->GetSize(1, 2) + triangle->GetSize(2, 0);
    }

    return 0.0;
}