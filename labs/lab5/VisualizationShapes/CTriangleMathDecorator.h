#pragma once
#include "IMathDecorator.h"

class CTriangleMathDecorator : public IMathDecorator
{
	public:
		CTriangleMathDecorator(IShape* shape) : IMathDecorator(shape) {}
		CTriangleMathDecorator() : IMathDecorator(nullptr) {}

		float GetArea() const override;
		float GetPerimeter() const override;
};

