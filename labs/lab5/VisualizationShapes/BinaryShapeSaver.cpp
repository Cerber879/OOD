#include "BinaryShapesSaver.h"

#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "Composite.h"

void BinaryShapesSaver::SaveShapes(const std::vector<std::shared_ptr<IShape>>& shapes, std::ostream& stream)
{
    for (std::shared_ptr<IShape> shape : shapes)
    {
        if (dynamic_cast<CRectangle*>(shape.get()) != nullptr)
        {
            CRectangle* rectangle = dynamic_cast<CRectangle*>(shape.get());
            sf::RectangleShape rectangleShape = rectangle->GetRectangleShape();
            SaveRectangleData(stream, rectangleShape);
        }
        else if (dynamic_cast<CCircle*>(shape.get()) != nullptr)
        {
            CCircle* circle = dynamic_cast<CCircle*>(shape.get());
            sf::CircleShape circleShape = circle->GetCircleShape();
            SaveCircleData(stream, circleShape);
        }
        else if (dynamic_cast<CTriangle*>(shape.get()) != nullptr)
        {
            CTriangle* rectangle = dynamic_cast<CTriangle*>(shape.get());
            sf::ConvexShape convexShape = rectangle->GetConvexShape();
            SaveTriangleData(stream, convexShape);
        }
        else if (dynamic_cast<Composite*>(shape.get()) != nullptr)
        {
            Composite* composite = dynamic_cast<Composite*>(shape.get());
            sf::FloatRect floatRect = composite->GetBoundingBox();
            std::vector<std::shared_ptr<IShape>> children = composite->GetChildren();
            SaveCompositeData(stream, children, floatRect);
        }
    }
}

void BinaryShapesSaver::SaveRectangleData(std::ostream& stream, sf::RectangleShape& rectangleShape)
{
    auto size = rectangleShape.getSize();
    auto fillColor = rectangleShape.getFillColor().toInteger();
    auto outlineColor = rectangleShape.getOutlineColor().toInteger();
    auto outlineThickness = rectangleShape.getOutlineThickness();
    auto position = rectangleShape.getPosition();

    uint32_t typeLength = static_cast<uint32_t>(Constants::TypeShape::RECTANGLE.size());
    stream.write(reinterpret_cast<const char*>(&typeLength), sizeof(typeLength));
    stream.write(Constants::TypeShape::RECTANGLE.data(), typeLength);

    stream.write(reinterpret_cast<const char*>(&size.x), sizeof(size.x));
    stream.write(reinterpret_cast<const char*>(&size.y), sizeof(size.y));
    stream.write(reinterpret_cast<const char*>(&fillColor), sizeof(fillColor));
    stream.write(reinterpret_cast<const char*>(&outlineColor), sizeof(outlineColor));
    stream.write(reinterpret_cast<const char*>(&outlineThickness), sizeof(outlineThickness));
    stream.write(reinterpret_cast<const char*>(&position.x), sizeof(position.x));
    stream.write(reinterpret_cast<const char*>(&position.y), sizeof(position.y));
}

void BinaryShapesSaver::SaveCircleData(std::ostream& stream, sf::CircleShape& circleShape)
{
    auto radius = circleShape.getRadius();
    auto fillColor = circleShape.getFillColor().toInteger();
    auto outlineColor = circleShape.getOutlineColor().toInteger();
    auto outlineThickness = circleShape.getOutlineThickness();
    auto position = circleShape.getPosition();

    uint32_t typeLength = static_cast<uint32_t>(Constants::TypeShape::CIRCLE.size());
    stream.write(reinterpret_cast<const char*>(&typeLength), sizeof(typeLength));
    stream.write(Constants::TypeShape::CIRCLE.data(), typeLength);

    stream.write(reinterpret_cast<const char*>(&radius), sizeof(radius));
    stream.write(reinterpret_cast<const char*>(&fillColor), sizeof(fillColor));
    stream.write(reinterpret_cast<const char*>(&outlineColor), sizeof(outlineColor));
    stream.write(reinterpret_cast<const char*>(&outlineThickness), sizeof(outlineThickness));
    stream.write(reinterpret_cast<const char*>(&position.x), sizeof(position.x));
    stream.write(reinterpret_cast<const char*>(&position.y), sizeof(position.y));
}

void BinaryShapesSaver::SaveTriangleData(std::ostream& stream, sf::ConvexShape& triangleShape)
{
    sf::Vector2f points[3];
    for (size_t i = 0; i < 3; ++i)
    {
        points[i] = triangleShape.getPoint(i);
    }
    auto fillColor = triangleShape.getFillColor().toInteger();
    auto outlineColor = triangleShape.getOutlineColor().toInteger();
    auto outlineThickness = triangleShape.getOutlineThickness();

    uint32_t typeLength = static_cast<uint32_t>(Constants::TypeShape::TRIANGLE.size());
    stream.write(reinterpret_cast<const char*>(&typeLength), sizeof(typeLength));
    stream.write(Constants::TypeShape::TRIANGLE.data(), typeLength);

    for (size_t i = 0; i < 3; ++i) 
    {
        stream.write(reinterpret_cast<const char*>(&points[i].x), sizeof(points[i].x));
        stream.write(reinterpret_cast<const char*>(&points[i].y), sizeof(points[i].y));
    }
    stream.write(reinterpret_cast<const char*>(&fillColor), sizeof(fillColor));
    stream.write(reinterpret_cast<const char*>(&outlineColor), sizeof(outlineColor));
    stream.write(reinterpret_cast<const char*>(&outlineThickness), sizeof(outlineThickness));
}

void BinaryShapesSaver::SaveCompositeData(std::ostream& stream, std::vector<std::shared_ptr<IShape>>& children, sf::FloatRect& boundingBox)
{
    uint32_t typeLength = static_cast<uint32_t>(Constants::TypeShape::COMPOSITE.size());
    stream.write(reinterpret_cast<const char*>(&typeLength), sizeof(typeLength));
    stream.write(Constants::TypeShape::COMPOSITE.data(), typeLength);

    stream.write(reinterpret_cast<const char*>(&boundingBox.left), sizeof(boundingBox.left));
    stream.write(reinterpret_cast<const char*>(&boundingBox.top), sizeof(boundingBox.top));
    stream.write(reinterpret_cast<const char*>(&boundingBox.width), sizeof(boundingBox.width));
    stream.write(reinterpret_cast<const char*>(&boundingBox.height), sizeof(boundingBox.height));

    size_t size = children.size();
    stream.write(reinterpret_cast<const char*>(&size), sizeof(size));

    BinaryShapesSaver saver;
    saver.SaveShapes(children, stream);
}
