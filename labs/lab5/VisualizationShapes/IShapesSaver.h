#pragma once

#include <memory>
#include "IShape.h"

class IShapesSaver 
{
public:
    virtual void SaveShapes(const std::vector<std::shared_ptr<IShape>>& shapes, std::ostream& stream) = 0;
    virtual ~IShapesSaver() = default;
};
