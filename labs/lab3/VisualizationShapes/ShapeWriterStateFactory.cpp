#include "ShapeWriterStateFactory.h"

ShapeWriterStateFactory::ShapeWriterStateFactory()
{
    states[Constants::TypeShape::RECTANGLE] = std::make_unique<RectangleWriterState>();
    states[Constants::TypeShape::CIRCLE] = std::make_unique<CircleWriterState>();
    states[Constants::TypeShape::TRIANGLE] = std::make_unique<TriangleWriterState>();
}

IShapeWriterState* ShapeWriterStateFactory::GetState(const std::string& shapeType)
{
    auto it = states.find(shapeType);

    if (it != states.end())
    {
        return it->second.get();
    }

    return nullptr;
}