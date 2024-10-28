#pragma once
#include "CDrawDecorator.h"

class CCircleDrawDecorator : public CDrawDecorator
{
	public:
		CCircleDrawDecorator(CShape* shape) : CDrawDecorator(shape) {}
		CCircleDrawDecorator() : CDrawDecorator(nullptr) {}

		void Draw(sf::RenderWindow& window) const override;
};

