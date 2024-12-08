#include "CTriangleDrawDecorator.h"
#include "CTriangle.h"

void CTriangleDrawDecorator::Draw(sf::RenderWindow& window) const
{
    CTriangle* triangle = dynamic_cast<CTriangle*>(shape);

    if (triangle)
    {
        window.draw(triangle->GetConvexShape());

        if (triangle->IsSelected())
        {
            sf::FloatRect boundingBox = triangle->GetBoundingBox();

            // Создаем прямоугольную рамку
            sf::RectangleShape selectionRectangle;
            selectionRectangle.setSize(sf::Vector2f(boundingBox.width, boundingBox.height));
            selectionRectangle.setPosition(sf::Vector2f(boundingBox.left, boundingBox.top));
            selectionRectangle.setFillColor(sf::Color::Transparent);
            selectionRectangle.setOutlineThickness(2);
            selectionRectangle.setOutlineColor(sf::Color::Green);
            window.draw(selectionRectangle);

            // Рисование маркеров на углах рамки
            sf::CircleShape marker(5);
            marker.setFillColor(sf::Color::Green);

            // Верхний левый угол
            marker.setPosition(sf::Vector2f(boundingBox.left - 5, boundingBox.top - 5));
            window.draw(marker);

            // Верхний правый угол
            marker.setPosition(sf::Vector2f(boundingBox.left + boundingBox.width - 5, boundingBox.top - 5));
            window.draw(marker);

            // Нижний левый угол
            marker.setPosition(sf::Vector2f(boundingBox.left - 5, boundingBox.top + boundingBox.height - 5));
            window.draw(marker);

            // Нижний правый угол
            marker.setPosition(sf::Vector2f(boundingBox.left + boundingBox.width - 5, boundingBox.top + boundingBox.height - 5));
            window.draw(marker);
        }
    }
}
