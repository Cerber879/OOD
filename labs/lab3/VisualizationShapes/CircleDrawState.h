#pragma once

#include "IShapeDrawState.h"
#include "CCircleDrawDecorator.h"

class CircleDrawState : public IShapeDrawState
{
    public:
        void DrawShape(sf::RenderWindow& window, const std::shared_ptr<IShape>& shape) override;
};