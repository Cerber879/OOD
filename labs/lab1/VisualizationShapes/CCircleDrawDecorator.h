#pragma once
#include "CDrawDecorator.h"

class CCircleDrawDecorator : public CDrawDecorator
{
	public:
		CCircleDrawDecorator(CShape* shape) : CDrawDecorator(shape) {}
		CCircleDrawDecorator() : CDrawDecorator(nullptr) {}

		std::string GetType() const override;

		void Draw(sf::RenderWindow& window) const override;
};

