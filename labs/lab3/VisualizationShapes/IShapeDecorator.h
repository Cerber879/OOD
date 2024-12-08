#pragma once
#include "IShape.h"

class IShapeDecorator : public IShape
{
    public:
        IShapeDecorator(IShape* shape) : shape(shape) {}
    protected:
        IShape* shape;
};