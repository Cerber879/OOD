#pragma once
#include "CShapeDecorator.h"

class CMathDecorator : public CShapeDecorator
{
    public:
        CMathDecorator(CShape* shape) : CShapeDecorator(shape) {}

        virtual double GetArea() const = 0;
        virtual double GetPerimeter() const = 0;
};