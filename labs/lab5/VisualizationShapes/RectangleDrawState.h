#pragma once

#include "IShapeDrawState.h"
#include "CRectangleDrawDecorator.h"

class RectangleDrawState : public IShapeDrawState 
{
    public:
        void DrawShape(sf::RenderWindow& window, const std::shared_ptr<IShape>& shape) override;
};