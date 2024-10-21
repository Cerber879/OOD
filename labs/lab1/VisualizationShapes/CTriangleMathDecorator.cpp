#include "CTriangleMathDecorator.h"
#include "CTriangle.h"

std::string CTriangleMathDecorator::GetType() const
{
    return TRIANGLE;
}

double CTriangleMathDecorator::GetArea() const
{
    CTriangle* triangle = dynamic_cast<CTriangle*>(shape);

    if (triangle)
    {
        double s = (triangle->GetFirstSize() + triangle->GetSecondSize() + triangle->GetThirdSize()) / TWO;

        return std::sqrt(s * (s - triangle->GetFirstSize()) * (s - triangle->GetSecondSize()) * (s - triangle->GetThirdSize()));
    }

    return 0.0;
}

double CTriangleMathDecorator::GetPerimeter() const
{
    CTriangle* triangle = dynamic_cast<CTriangle*>(shape);

    if (triangle)
    {
        return triangle->GetFirstSize() + triangle->GetSecondSize() + triangle->GetThirdSize();
    }

    return 0.0;
}