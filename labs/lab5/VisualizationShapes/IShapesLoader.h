#pragma once

#include <memory>
#include "IShape.h"

class IShapesLoader
{
public:
    virtual std::vector<std::shared_ptr<IShape>> LoadShapes(std::istream& stream) = 0;
    virtual ~IShapesLoader() = default;
};
