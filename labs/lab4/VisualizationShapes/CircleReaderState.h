#pragma once

#include "IShapeReaderState.h"
#include "CCircleFileDecorator.h"

class CircleReaderState : public IShapeReaderState
{
public:
    std::shared_ptr<IShape> ReadShape(std::istream& iss) override;
};