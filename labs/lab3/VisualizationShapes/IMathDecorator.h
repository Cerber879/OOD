#pragma once
#include "IShapeDecorator.h"

class IMathDecorator : public IShapeDecorator
{
    public:
        IMathDecorator(IShape* shape) : IShapeDecorator(shape) {}

        virtual float GetArea() const = 0;
        virtual float GetPerimeter() const = 0;
};