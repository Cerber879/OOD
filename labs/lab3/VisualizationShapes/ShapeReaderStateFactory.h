#pragma once

#include <unordered_map>

#include "IShapeReaderState.h"

#include "TriangleReaderState.h"
#include "RectangleReaderState.h"
#include "CircleReaderState.h"

class ShapeReaderStateFactory
{
    public:
        ShapeReaderStateFactory();

        IShapeReaderState* GetState(const std::string& shapeType);

    private:
        std::unordered_map<std::string, std::unique_ptr<IShapeReaderState>> m_states;
};