#pragma once

#include "IShapeDrawState.h"
#include "CTriangleDrawDecorator.h"

class TriangleDrawState : public IShapeDrawState 
{
    public:
        void DrawShape(sf::RenderWindow& window, const std::shared_ptr<IShape>& shape) override;
};