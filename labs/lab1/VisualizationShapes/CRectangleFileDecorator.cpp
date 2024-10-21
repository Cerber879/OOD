#include "CRectangleFileDecorator.h"
#include "CRectangleMathDecorator.h"
#include "CRectangle.h"

std::string CRectangleFileDecorator::GetType() const
{
    return RECTANGLE;
}

std::shared_ptr<CShape> CRectangleFileDecorator::ReadShape(std::istream& in)
{
    sf::Vector2f firstPoint, secondPoint;
    char ch;

    // read coordinates first point
    in >> ch >> ch >> ch;
    in >> firstPoint.x;
    in >> ch;
    in >> firstPoint.y;

    // read coordinates second point
    in >> ch >> ch >> ch >> ch;
    in >> secondPoint.x;
    in >> ch;
    in >> secondPoint.y;

    CRectangle* rectangle = new CRectangle(firstPoint, secondPoint);

    return std::make_shared<CRectangle>(*rectangle);
}

std::string CRectangleFileDecorator::WriteShape(const std::shared_ptr<CShape>& shape) const
{
    if (!shape)
    {   
        return "";
    }

    CRectangleMathDecorator mathDecorator(shape.get());

    std::stringstream ss;
    ss << STR_PREFIX_RECTANGLE
        << STR_PREFIX_PERIMETER << mathDecorator.GetPerimeter()
        << SEMICOLON
        << STR_PREFIX_AREA << mathDecorator.GetArea()
        << std::endl;

    return ss.str();
}

