#pragma once
#include "CMathDecorator.h"

class CCircleMathDecorator : public CMathDecorator
{
	public:
		CCircleMathDecorator(CShape* shape) : CMathDecorator(shape) {}

		float GetArea() const override;
		float GetPerimeter() const override;
};
