#pragma once

#include "IShapesSaver.h"

class BinaryShapesSaver : public IShapesSaver
{
public:
    void SaveShapes(const std::vector<std::shared_ptr<IShape>>& shapes, std::ostream& stream) override;

private:
    void SaveRectangleData(std::ostream& stream, sf::RectangleShape& rectangleShape);
    void SaveCircleData(std::ostream& stream, sf::CircleShape& rectangleShape);
    void SaveTriangleData(std::ostream& stream, sf::ConvexShape& rectangleShape);
    void SaveCompositeData(std::ostream& stream, std::vector<std::shared_ptr<IShape>>& children, sf::FloatRect& boundingBox);
};
