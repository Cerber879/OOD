#pragma once

#include "IShape.h"

class Builder
{
public:
	virtual void Build(ShapeData& shapeData) = 0;
	virtual std::shared_ptr<IShape> GetResult() = 0;
};