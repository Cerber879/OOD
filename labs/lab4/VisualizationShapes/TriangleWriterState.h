#pragma once

#include "IShapeWriterState.h"
#include "CTriangleFileDecorator.h"

class TriangleWriterState : public IShapeWriterState 
{
    public:
        void WriteShape(std::ostream& os, const std::shared_ptr<IShape>& shape) override;
};