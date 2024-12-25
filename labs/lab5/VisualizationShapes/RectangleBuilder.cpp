#include "RectangleBuilder.h"
#include "CRectangle.h"

void RectangleBuilder::Build(ShapeData& data) 
{
    if (auto rectangleData = std::get_if<RectangleData>(&data)) 
    {
        rectangleShape.setSize(sf::Vector2f(rectangleData->width, rectangleData->height));
        rectangleShape.setFillColor(sf::Color(rectangleData->fillColorInt));
        rectangleShape.setOutlineColor(sf::Color(rectangleData->outlineColorInt));
        rectangleShape.setOutlineThickness(rectangleData->outlineThickness);
        rectangleShape.setPosition(rectangleData->positionX, rectangleData->positionY);
    }
}

std::shared_ptr<IShape> RectangleBuilder::GetResult()
{
    return std::make_shared<CRectangle>(rectangleShape);
}
