#include "TriangleDrawState.h"

void TriangleDrawState::DrawShape(sf::RenderWindow& window, const std::shared_ptr<IShape>& shape)
{
    CTriangleDrawDecorator triangle(shape.get());
    triangle.Draw(window);
}
