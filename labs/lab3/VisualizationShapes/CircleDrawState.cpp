#include "CircleDrawState.h"

void CircleDrawState::DrawShape(sf::RenderWindow& window, const std::shared_ptr<IShape>& shape)
{
    CCircleDrawDecorator circle(shape.get());
    circle.Draw(window);
}