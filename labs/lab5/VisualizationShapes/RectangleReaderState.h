#pragma once

#include "IShapeReaderState.h"
#include "CRectangleFileDecorator.h"

class RectangleReaderState : public IShapeReaderState
{
public:
    std::shared_ptr<IShape> ReadShape(std::istream& iss) override;
};