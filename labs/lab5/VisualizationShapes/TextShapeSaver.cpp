#include "TextShapesSaver.h"

#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "Composite.h"

void TextShapesSaver::SaveShapes(const std::vector<std::shared_ptr<IShape>>& shapes, std::ostream& stream)
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

void TextShapesSaver::SaveRectangleData(std::ostream& stream, sf::RectangleShape& rectangleShape)
{
    stream << Constants::TypeShape::RECTANGLE << " "
        << rectangleShape.getSize().x << " "
        << rectangleShape.getSize().y << " "
        << rectangleShape.getFillColor().toInteger() << " "
        << rectangleShape.getOutlineColor().toInteger() << " "
        << rectangleShape.getOutlineThickness() << " "
        << rectangleShape.getPosition().x << " "
        << rectangleShape.getPosition().y << "\n";
}

void TextShapesSaver::SaveCircleData(std::ostream& stream, sf::CircleShape& cirlceShape)
{
    stream << Constants::TypeShape::CIRCLE << " "
        << cirlceShape.getRadius() << " "
        << cirlceShape.getFillColor().toInteger() << " "
        << cirlceShape.getOutlineColor().toInteger() << " "
        << cirlceShape.getOutlineThickness() << " "
        << cirlceShape.getPosition().x << " "
        << cirlceShape.getPosition().y << "\n";
}

void TextShapesSaver::SaveTriangleData(std::ostream& stream, sf::ConvexShape& triangleShape)
{
    stream << Constants::TypeShape::TRIANGLE << " ";
    for (size_t i = 0; i < 3; ++i)
    {
        stream
            << triangleShape.getPoint(i).x << " "
            << triangleShape.getPoint(i).y << " ";
    }
    stream << triangleShape.getFillColor().toInteger() << " "
        << triangleShape.getOutlineColor().toInteger() << " "
        << triangleShape.getOutlineThickness() << "\n";
}

void TextShapesSaver::SaveCompositeData(std::ostream& stream, std::vector<std::shared_ptr<IShape>>& children, sf::FloatRect& boundingBox)
{
    stream << Constants::TypeShape::COMPOSITE << " "
        << boundingBox.left << " "
        << boundingBox.top << " "
        << boundingBox.width << " "
        << boundingBox.height << " "
        << children.size() << "\n";

    TextShapesSaver saver;
    saver.SaveShapes(children, stream);
}

