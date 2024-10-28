#pragma once
#include "CShapeDecorator.h"

class CMathDecorator : public CShapeDecorator
{
    public:
        CMathDecorator(CShape* shape) : CShapeDecorator(shape) {}

        virtual float GetArea() const = 0;
        virtual float GetPerimeter() const = 0;
};