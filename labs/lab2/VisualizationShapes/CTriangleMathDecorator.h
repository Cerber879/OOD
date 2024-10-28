#pragma once
#include "CMathDecorator.h"

class CTriangleMathDecorator : public CMathDecorator
{
	public:
		CTriangleMathDecorator(CShape* shape) : CMathDecorator(shape) {}
		CTriangleMathDecorator() : CMathDecorator(nullptr) {}

		float GetArea() const override;
		float GetPerimeter() const override;
};

