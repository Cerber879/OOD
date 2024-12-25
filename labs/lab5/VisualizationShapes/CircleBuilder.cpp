#include "CircleBuilder.h"
#include "CCircle.h"

void CircleBuilder::Build(ShapeData& data) 
{
    if (auto circleData = std::get_if<CircleData>(&data)) 
    {
        circleShape.setRadius(circleData->radius);
        circleShape.setFillColor(sf::Color(circleData->fillColorInt));
        circleShape.setOutlineColor(sf::Color(circleData->outlineColorInt));
        circleShape.setOutlineThickness(circleData->outlineThickness);
        circleShape.setPosition(circleData->positionX, circleData->positionY);
    }
}

std::shared_ptr<IShape> CircleBuilder::GetResult()
{
    return std::make_shared<CCircle>(circleShape);
}
