#pragma once
#include "CMathDecorator.h"

class CCircleMathDecorator : public CMathDecorator
{
	public:
		CCircleMathDecorator(CShape* shape) : CMathDecorator(shape) {}

		std::string GetType() const override;

		double GetArea() const override;
		double GetPerimeter() const override;
};
