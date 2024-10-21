#pragma once
#include "CMathDecorator.h"

class CRectangleMathDecorator : public CMathDecorator
{
	public:
		CRectangleMathDecorator(CShape* shape) : CMathDecorator(shape) {}
		CRectangleMathDecorator() : CMathDecorator(nullptr) {}

		std::string GetType() const override;

		double GetArea() const override;
		double GetPerimeter() const override;
};

