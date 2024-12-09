#pragma once

#include "IShapeWriterState.h"
#include "CCircleFileDecorator.h"

class CircleWriterState : public IShapeWriterState 
{
    public:
        void WriteShape(std::ostream& os, const std::shared_ptr<IShape>& shape) override;
};