#pragma once
#include "CShapeDecorator.h"

class CDrawDecorator : public CShapeDecorator
{
    public:
        CDrawDecorator(CShape* shape) : CShapeDecorator(shape) {}

        virtual void Draw(sf::RenderWindow& window) const = 0;
};