#include "CCircleFileDecorator.h"
#include "CCircleMathDecorator.h"
#include "CCircle.h"
#include "ToolPanelManager.h"

std::shared_ptr<IShape> CCircleFileDecorator::ReadShape(std::istream& in)
{
    sf::Vector2f center;
    float radius;
    char ch;

    in >> ch >> ch;
    in >> center.x;
    in >> ch;
    in >> center.y;

    in >> ch >> ch >> ch;
    in >> radius;

    return std::make_shared<CCircle>
        (
            center, radius,
            ToolPanelManager::GetInstance().GetFillColor(),
            ToolPanelManager::GetInstance().GetOutlineColor(),
            ToolPanelManager::GetInstance().GetOutlineThickness()
        );
}

std::string CCircleFileDecorator::WriteShape(const std::shared_ptr<IShape>& shape) const
{
    if (!shape)
    {
        return "";
    }

    CCircleMathDecorator mathDecorator(shape.get());

    std::stringstream ss;
    ss << Constants::PrefixShape::STR_PREFIX_CIRCLE
        << Constants::PrefixMath::STR_PREFIX_PERIMETER << mathDecorator.GetPerimeter()
        << Constants::Char::SEMICOLON
        << Constants::PrefixMath::STR_PREFIX_AREA << mathDecorator.GetArea()
        << std::endl;

    return ss.str();
}
