#pragma once

#include "IShape.h"

class IShapeReaderState
{
    public:
        virtual ~IShapeReaderState() = default;
        virtual std::shared_ptr<IShape> ReadShape(std::istream& iss) = 0;
};