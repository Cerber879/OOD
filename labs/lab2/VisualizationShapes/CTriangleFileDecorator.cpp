#include "CTriangleFileDecorator.h"
#include "CTriangleMathDecorator.h"
#include "CTriangle.h"

std::shared_ptr<CShape> CTriangleFileDecorator::ReadShape(std::istream& in)
{
    sf::Vector2f p1, p2, p3;
    char ch;

    // read coordinates first point
    in >> ch >> ch >> ch;
    in >> p1.x;
    in >> ch;
    in >> p1.y;

    // read coordinates second point
    in >> ch >> ch >> ch >> ch;
    in >> p2.x;
    in >> ch;
    in >> p2.y;

    // read coordinates third point
    in >> ch >> ch >> ch >> ch;
    in >> p3.x;
    in >> ch;
    in >> p3.y;

    return std::make_shared<CTriangle>(p1, p2, p3);
}

std::string CTriangleFileDecorator::WriteShape(const std::shared_ptr<CShape>& shape) const
{
    if (!shape)
    {
        return "";
    }

    CTriangleMathDecorator mathDecorator(shape.get());

    std::stringstream ss;
    ss << STR_PREFIX_TRIANGLE
        << STR_PREFIX_PERIMETER << mathDecorator.GetPerimeter()
        << SEMICOLON
        << STR_PREFIX_AREA << mathDecorator.GetArea()
        << std::endl;

    return ss.str();
}
