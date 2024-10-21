#include "CCircleFileDecorator.h"
#include "CCircleMathDecorator.h"
#include "CCircle.h"

std::string CCircleFileDecorator::GetType() const
{
    return CIRCLE;
}

std::shared_ptr<CShape> CCircleFileDecorator::ReadShape(std::istream& in)
{
    sf::Vector2f center;
    double radius;
    char ch;

    in >> ch >> ch;
    in >> center.x;
    in >> ch;
    in >> center.y;

    in >> ch >> ch >> ch;
    in >> radius;

    return std::make_shared<CCircle>(center, radius);
}

std::string CCircleFileDecorator::WriteShape(const std::shared_ptr<CShape>& shape) const
{
    if (!shape)
    {
        return "";
    }

    CCircleMathDecorator mathDecorator(shape.get());

    std::stringstream ss;
    ss << STR_PREFIX_CIRCLE
        << STR_PREFIX_PERIMETER << mathDecorator.GetPerimeter()
        << SEMICOLON
        << STR_PREFIX_AREA << mathDecorator.GetArea()
        << std::endl;

    return ss.str();
}
