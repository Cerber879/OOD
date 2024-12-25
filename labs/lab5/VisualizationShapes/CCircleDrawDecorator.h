#pragma once
#include "IDrawDecorator.h"

class CCircleDrawDecorator : public IDrawDecorator
{
	public:
		CCircleDrawDecorator(IShape* shape) : IDrawDecorator(shape) {}
		CCircleDrawDecorator() : IDrawDecorator(nullptr) {}

		void Draw(sf::RenderWindow& window) const override;
};

