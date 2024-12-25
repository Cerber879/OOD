#pragma once
#include "IShapeDecorator.h"

class IDrawDecorator : public IShapeDecorator
{
    public:
        IDrawDecorator(IShape* shape) : IShapeDecorator(shape) {}

        virtual void Draw(sf::RenderWindow& window) const = 0;
};