#pragma once

#include "IShape.h"

class IShapeWriterState 
{
    public:
        virtual ~IShapeWriterState() = default;
        virtual void WriteShape(std::ostream& os, const std::shared_ptr<IShape>& shape) = 0;
};