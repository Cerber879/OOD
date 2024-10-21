#pragma once
#include "CDrawDecorator.h"

class CTriangleDrawDecorator : public CDrawDecorator
{
public:
	CTriangleDrawDecorator(CShape* shape) : CDrawDecorator(shape) {}
	CTriangleDrawDecorator() : CDrawDecorator(nullptr) {}

	std::string GetType() const override;

	void Draw(sf::RenderWindow& window) const override;
};

