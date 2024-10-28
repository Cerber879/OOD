#include "CCircleDrawDecorator.h"
#include "CCircle.h"

void CCircleDrawDecorator::Draw(sf::RenderWindow& window) const
{
    CCircle* circle = dynamic_cast<CCircle*>(shape);
    sf::CircleShape circleShape = circle->GetCircleShape();

    if (circle)
    {
        window.draw(circleShape);

        if (circle->IsSelected())
        {
            sf::CircleShape selectionCircle = circleShape;
            selectionCircle.setFillColor(sf::Color::Transparent);
            selectionCircle.setOutlineThickness(2);
            selectionCircle.setOutlineColor(sf::Color::Green);
            window.draw(selectionCircle);

            // Рисование маркеров
            sf::CircleShape marker(5);
            marker.setFillColor(sf::Color::Green);
            marker.setPosition(sf::Vector2f(circle->GetCenter().x - 5, circle->GetCenter().y - circleShape.getRadius() - 5));
            window.draw(marker);
            marker.setPosition(sf::Vector2f(circle->GetCenter().x - 5, circle->GetCenter().y + circleShape.getRadius() - 5));
            window.draw(marker);
            marker.setPosition(sf::Vector2f(circle->GetCenter().x - circleShape.getRadius() - 5, circle->GetCenter().y - 5));
            window.draw(marker);
            marker.setPosition(sf::Vector2f(circle->GetCenter().x + circleShape.getRadius() - 5, circle->GetCenter().y - 5));
            window.draw(marker);
        }
    }
}
