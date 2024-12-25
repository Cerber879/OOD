#pragma once
#include "IDrawDecorator.h"

class CRectangleDrawDecorator : public IDrawDecorator
{
	public:
		CRectangleDrawDecorator(IShape* shape) : IDrawDecorator(shape) {}
		CRectangleDrawDecorator() : IDrawDecorator(nullptr) {}

		void Draw(sf::RenderWindow& window) const override;
};

