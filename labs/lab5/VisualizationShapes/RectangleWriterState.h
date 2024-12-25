#pragma once

#include "IShapeWriterState.h"
#include "CRectangleFileDecorator.h"

class RectangleWriterState : public IShapeWriterState 
{
    public:
        void WriteShape(std::ostream& os, const std::shared_ptr<IShape>& shape) override;
};