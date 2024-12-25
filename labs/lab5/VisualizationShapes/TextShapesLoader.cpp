#include "TextShapesLoader.h"
#include "CircleBuilder.h"
#include "RectangleBuilder.h"
#include "TriangleBuilder.h"
#include "CompositeBuilder.h"
#include "Composite.h"
#include <sstream>

std::vector<std::shared_ptr<IShape>> TextShapesLoader::LoadShapes(std::istream& stream)
{
    std::string line;
    while (getline(stream, line))
    {
        std::istringstream iss(line);
        std::shared_ptr<IShape> shape = ProcessingLine(stream, iss);
        shapes.push_back(shape);
    }

    return shapes;
}

std::shared_ptr<IShape> TextShapesLoader::ProcessingLine(std::istream& stream, std::istream& line)
{
    std::string shapeType;
    line >> shapeType;

    if (shapeType == Constants::TypeShape::CIRCLE)
    {
        ShapeData data = ReadCircleData(line);
        CircleBuilder builder;
        builder.Build(data);
        return builder.GetResult();
    }
    else if (shapeType == Constants::TypeShape::RECTANGLE)
    {
        ShapeData data = ReadRectangleData(line);
        RectangleBuilder builder;
        builder.Build(data);
        return builder.GetResult();
    }
    else if (shapeType == Constants::TypeShape::TRIANGLE)
    {
        ShapeData data = ReadTriangleData(line);
        TriangleBuilder builder;
        builder.Build(data);
        return builder.GetResult();
    }
    else if (shapeType == Constants::TypeShape::COMPOSITE)
    {
        ShapeData data = ReadCompositeData(line);
        std::vector<std::shared_ptr<IShape>> children;
        if (auto compositeData = std::get_if<CompositeData>(&data))
        {
            std::string line;
            for (int i = 0; i < compositeData->size; i++)
            {
                if (getline(stream, line))
                {
                    std::istringstream iss(line);
                    std::shared_ptr<IShape> shape = ProcessingLine(stream, iss);
                    children.push_back(shape);
                }
            }
        }

        CompositeBuilder builder;
        builder.Build(data);

        std::shared_ptr<IShape> shape = builder.GetResult();

        if (std::shared_ptr<Composite> composite = std::dynamic_pointer_cast<Composite>(shape))
        {
            composite->SetChildren(children);
        }

        return shape;
    }
}

CircleData TextShapesLoader::ReadCircleData(std::istream& stream)
{
    CircleData data;

    stream 
        >> data.radius 
        >> data.fillColorInt 
        >> data.outlineColorInt
        >> data.outlineThickness
        >> data.positionX 
        >> data.positionY;

    return data;
}

RectangleData TextShapesLoader::ReadRectangleData(std::istream& stream)
{
    RectangleData data;

    stream 
        >> data.width 
        >> data.height
        >> data.fillColorInt
        >> data.outlineColorInt 
        >> data.outlineThickness
        >> data.positionX
        >> data.positionY;

    return data;
}

TriangleData TextShapesLoader::ReadTriangleData(std::istream& stream)
{
    TriangleData data;

    for (size_t i = 0; i < 3; ++i)
    {
        stream 
            >> data.points[i].x
            >> data.points[i].y;
    }

    stream 
        >> data.fillColorInt 
        >> data.outlineColorInt
        >> data.outlineThickness;

    return data;
}

CompositeData TextShapesLoader::ReadCompositeData(std::istream& stream)
{
    CompositeData data;

    stream
        >> data.left
        >> data.top
        >> data.width
        >> data.height
        >> data.size;

    return data;
}
