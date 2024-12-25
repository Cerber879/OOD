#pragma once
#include "IDrawDecorator.h"

class CTriangleDrawDecorator : public IDrawDecorator
{
	public:
		CTriangleDrawDecorator(IShape* shape) : IDrawDecorator(shape) {}
		CTriangleDrawDecorator() : IDrawDecorator(nullptr) {}

		void Draw(sf::RenderWindow& window) const override;
};

