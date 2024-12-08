#pragma once

#include "IShapeDrawState.h"
#include "CompositeDrawState.h"

class CompositeDrawState : public IShapeDrawState 
{
    public:
        void DrawShape(sf::RenderWindow& window, const std::shared_ptr<IShape>& shape) override;
};