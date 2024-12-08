#include "CRectangleFileDecorator.h"
#include "CRectangleMathDecorator.h"
#include "CRectangle.h"
#include "ToolPanelManager.h"

std::shared_ptr<IShape> CRectangleFileDecorator::ReadShape(std::istream& in)
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

    return std::make_shared<CRectangle>
        (
            firstPoint, secondPoint,
            ToolPanelManager::GetInstance().GetFillColor(),
            ToolPanelManager::GetInstance().GetOutlineColor(),
            ToolPanelManager::GetInstance().GetOutlineThickness()
        );
}

std::string CRectangleFileDecorator::WriteShape(const std::shared_ptr<IShape>& shape) const
{
    if (!shape)
    {   
        return "";
    }

    CRectangleMathDecorator mathDecorator(shape.get());

    std::stringstream ss;
    ss << Constants::PrefixShape::STR_PREFIX_RECTANGLE
        << Constants::PrefixMath::STR_PREFIX_PERIMETER << mathDecorator.GetPerimeter()
        << Constants::Char::SEMICOLON
        << Constants::PrefixMath::STR_PREFIX_AREA << mathDecorator.GetArea()
        << std::endl;

    return ss.str();
}

