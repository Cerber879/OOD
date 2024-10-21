#pragma once
#include "CMathDecorator.h"

class CTriangleMathDecorator : public CMathDecorator
{
	public:
		CTriangleMathDecorator(CShape* shape) : CMathDecorator(shape) {}
		CTriangleMathDecorator() : CMathDecorator(nullptr) {}

		std::string GetType() const override;

		double GetArea() const override;
		double GetPerimeter() const override;
};

