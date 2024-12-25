#pragma once
#include <unordered_map>
#include "IShapeDrawState.h"
#include "RectangleDrawState.h"
#include "CircleDrawState.h"
#include "TriangleDrawState.h"
#include "CompositeDrawState.h"
#include "Constants.h"

class ShapeDrawStateFactory 
{
    public:
        ShapeDrawStateFactory();

        IShapeDrawState* GetState(const std::string& shapeType);

    private:
        std::unordered_map<std::string, std::unique_ptr<IShapeDrawState>> states;
};