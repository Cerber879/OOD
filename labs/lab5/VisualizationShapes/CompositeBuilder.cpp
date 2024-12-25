#include "CompositeBuilder.h"
#include "Composite.h"
#include "TextShapesLoader.h"

void CompositeBuilder::Build(ShapeData& data)
{
    if (auto compositeData = std::get_if<CompositeData>(&data))
    {
        m_boundingBox = sf::FloatRect(compositeData->left, compositeData->top, compositeData->width, compositeData->height);
    }
}

std::shared_ptr<IShape> CompositeBuilder::GetResult()
{
    return std::make_shared<Composite>(m_boundingBox);
}
