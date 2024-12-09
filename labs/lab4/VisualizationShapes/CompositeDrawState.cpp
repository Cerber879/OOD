#include "CompositeDrawState.h"

void CompositeDrawState::DrawShape(sf::RenderWindow& window, const std::shared_ptr<IShape>& shape)
{
    if(shape->GetType() == Constants::TypeShape::COMPOSITE)
        shape->Draw(window);
}
