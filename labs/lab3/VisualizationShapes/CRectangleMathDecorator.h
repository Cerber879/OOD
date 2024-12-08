#pragma once
#include "IMathDecorator.h"

class CRectangleMathDecorator : public IMathDecorator
{
	public:
		CRectangleMathDecorator(IShape* shape) : IMathDecorator(shape) {}
		CRectangleMathDecorator() : IMathDecorator(nullptr) {}

		float GetArea() const override;
		float GetPerimeter() const override;
};

