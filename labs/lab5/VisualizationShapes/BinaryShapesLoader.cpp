#include "BinaryShapesLoader.h"
#include "CircleBuilder.h"
#include "RectangleBuilder.h"
#include "TriangleBuilder.h"
#include "CompositeBuilder.h"
#include "Composite.h"

std::vector<std::shared_ptr<IShape>> BinaryShapesLoader::LoadShapes(std::istream& stream)
{
    uint32_t typeLength;

    while (stream.peek() != EOF)
    {
        stream.read(reinterpret_cast<char*>(&typeLength), sizeof(typeLength));
        std::string shapeType(typeLength, ' ');

        stream.read(&shapeType[0], typeLength);
        shapes.push_back(ProcessingLine(stream, shapeType));
    }

    return shapes;
}

std::shared_ptr<IShape> BinaryShapesLoader::ProcessingLine(std::istream& stream, std::string shapeType)
{
    std::shared_ptr<IShape> shape;

    auto buildShape = [&](auto& builder, ShapeData data) 
        {
            builder.Build(data);
            shape = builder.GetResult();
        };

    if (shapeType == Constants::TypeShape::CIRCLE)
    {
        CircleBuilder builder;
        buildShape(builder, ReadCircleData(stream));
    }
    else if (shapeType == Constants::TypeShape::RECTANGLE)
    {
        RectangleBuilder builder;
        buildShape(builder, ReadRectangleData(stream));
    }
    else if (shapeType == Constants::TypeShape::TRIANGLE)
    {
        TriangleBuilder builder;
        buildShape(builder, ReadTriangleData(stream));
    }
    else if (shapeType == Constants::TypeShape::COMPOSITE)
    {
        ShapeData data = ReadCompositeData(stream);

        CompositeBuilder builder;
        builder.Build(data);
        shape = builder.GetResult();

        auto composite = std::dynamic_pointer_cast<Composite>(shape);

        if (auto compositeData = std::get_if<CompositeData>(&data))
        {
            std::vector<std::shared_ptr<IShape>> children;
            uint32_t typeLength;

            for (int i = 0; i < compositeData->size; i++)
            {
                stream.read(reinterpret_cast<char*>(&typeLength), sizeof(typeLength));
                std::string shapeType(typeLength, ' ');

                stream.read(&shapeType[0], typeLength);
                children.push_back(ProcessingLine(stream, shapeType));
            }

            composite->SetChildren(children);
            shape = composite;
        }
    }

    return shape;
}

CircleData BinaryShapesLoader::ReadCircleData(std::istream& stream)
{
    CircleData data;
    stream.read(reinterpret_cast<char*>(&data), sizeof(CircleData));
    return data;
}

RectangleData BinaryShapesLoader::ReadRectangleData(std::istream& stream)
{
    RectangleData data;
    stream.read(reinterpret_cast<char*>(&data), sizeof(RectangleData));
    return data;
}

TriangleData BinaryShapesLoader::ReadTriangleData(std::istream& stream)
{
    TriangleData data;
    stream.read(reinterpret_cast<char*>(&data), sizeof(TriangleData));
    return data;
}

CompositeData BinaryShapesLoader::ReadCompositeData(std::istream& stream)
{
    CompositeData data;
    stream.read(reinterpret_cast<char*>(&data), sizeof(CompositeData));
    return data;
}
