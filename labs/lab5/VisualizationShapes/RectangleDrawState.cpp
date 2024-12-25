#include "RectangleDrawState.h"

void RectangleDrawState::DrawShape(sf::RenderWindow& window, const std::shared_ptr<IShape>& shape)
{
    CRectangleDrawDecorator rectangle(shape.get());
    rectangle.Draw(window);
}
