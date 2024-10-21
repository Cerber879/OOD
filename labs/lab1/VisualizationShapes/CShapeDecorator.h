#pragma once
#include "CShape.h"

class CShapeDecorator : public CShape
{
    public:
        CShapeDecorator(CShape* shape) : shape(shape) {}
    protected:
        CShape* shape;
};