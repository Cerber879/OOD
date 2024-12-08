#pragma once
#include "IMathDecorator.h"

class CCircleMathDecorator : public IMathDecorator
{
	public:
		CCircleMathDecorator(IShape* shape) : IMathDecorator(shape) {}

		float GetArea() const override;
		float GetPerimeter() const override;
};
