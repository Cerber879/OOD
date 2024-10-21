#pragma once
#include "CDrawDecorator.h"

class CRectangleDrawDecorator : public CDrawDecorator
{
	public:
		CRectangleDrawDecorator(CShape* shape) : CDrawDecorator(shape) {}
		CRectangleDrawDecorator() : CDrawDecorator(nullptr) {}

		std::string GetType() const override;

		void Draw(sf::RenderWindow& window) const override;
};

