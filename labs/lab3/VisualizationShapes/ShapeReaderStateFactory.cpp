#include "ShapeReaderStateFactory.h"

ShapeReaderStateFactory::ShapeReaderStateFactory()
{
    m_states[Constants::PrefixShape::STR_PREFIX_TRIANGLE] = std::make_unique<TriangleReaderState>();
    m_states[Constants::PrefixShape::STR_PREFIX_RECTANGLE] = std::make_unique<RectangleReaderState>();
    m_states[Constants::PrefixShape::STR_PREFIX_CIRCLE] = std::make_unique<CircleReaderState>();
}

IShapeReaderState* ShapeReaderStateFactory::GetState(const std::string& shapeType)
{
    auto it = m_states.find(shapeType);

    if (it != m_states.end())
    {
        return it->second.get();
    }

    return nullptr;
}
