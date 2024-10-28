#pragma once
#include "CMathDecorator.h"

class CRectangleMathDecorator : public CMathDecorator
{
	public:
		CRectangleMathDecorator(CShape* shape) : CMathDecorator(shape) {}
		CRectangleMathDecorator() : CMathDecorator(nullptr) {}

		float GetArea() const override;
		float GetPerimeter() const override;
};

