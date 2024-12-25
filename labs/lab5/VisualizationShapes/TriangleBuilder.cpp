#include "TriangleBuilder.h"
#include "CTriangle.h"

void TriangleBuilder::Build(ShapeData& data)
{
    if (auto convexData = std::get_if<TriangleData>(&data))
    {
        convexShape.setPointCount(3);
        for (size_t i = 0; i < 3; ++i)
        {
            convexShape.setPoint(i, convexData->points[i]);
        }
        convexShape.setFillColor(sf::Color(convexData->fillColorInt));
        convexShape.setOutlineColor(sf::Color(convexData->outlineColorInt));
        convexShape.setOutlineThickness(convexData->outlineThickness);
    }
}

std::shared_ptr<IShape> TriangleBuilder::GetResult()
{
    return std::make_shared<CTriangle>(convexShape);

}
