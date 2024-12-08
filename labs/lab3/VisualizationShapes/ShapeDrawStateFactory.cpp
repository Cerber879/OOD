#include "ShapeDrawStateFactory.h"

ShapeDrawStateFactory::ShapeDrawStateFactory()
{
    states[Constants::TypeShape::RECTANGLE] = std::make_unique<RectangleDrawState>();
    states[Constants::TypeShape::CIRCLE] = std::make_unique<CircleDrawState>();
    states[Constants::TypeShape::TRIANGLE] = std::make_unique<TriangleDrawState>();
    states[Constants::TypeShape::COMPOSITE] = std::make_unique<CompositeDrawState>();
}

IShapeDrawState* ShapeDrawStateFactory::GetState(const std::string& shapeType)
{
    auto it = states.find(shapeType);

    if (it != states.end())
    {
        return it->second.get();
    }

    return nullptr;
}