#pragma once

#include "IShapeReaderState.h"
#include "CTriangleFileDecorator.h"

class TriangleReaderState : public IShapeReaderState
{
    public:
        std::shared_ptr<IShape> ReadShape(std::istream& iss) override;
};