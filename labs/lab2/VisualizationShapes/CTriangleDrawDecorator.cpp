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
            sf::ConvexShape selectionTriangle(3);
            selectionTriangle.setPoint(0, triangle->GetPoint(0));
            selectionTriangle.setPoint(1, triangle->GetPoint(1));
            selectionTriangle.setPoint(2, triangle->GetPoint(2));
            selectionTriangle.setFillColor(sf::Color::Transparent);
            selectionTriangle.setOutlineThickness(2);
            selectionTriangle.setOutlineColor(sf::Color::Green);
            window.draw(selectionTriangle);

            // Рисование маркеров
            sf::CircleShape marker(5);
            marker.setFillColor(sf::Color::Green);
            marker.setPosition(sf::Vector2f(triangle->GetPoint(0).x - 5, triangle->GetPoint(0).y - 5));
            window.draw(marker);
            marker.setPosition(sf::Vector2f(triangle->GetPoint(1).x - 5, triangle->GetPoint(1).y - 5));
            window.draw(marker);
            marker.setPosition(sf::Vector2f(triangle->GetPoint(2).x - 5, triangle->GetPoint(2).y - 5));
            window.draw(marker);
        }
    }
}
