#pragma once

#include "IShape.h"

class IShapeDrawState 
{
    public:
        virtual ~IShapeDrawState() = default;
        virtual void DrawShape(sf::RenderWindow& window, const std::shared_ptr<IShape>& shape) = 0;
};