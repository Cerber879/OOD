#include "CRectangleDrawDecorator.h"
#include "CRectangle.h"

void CRectangleDrawDecorator::Draw(sf::RenderWindow& window) const
{
    CRectangle* rectangle = dynamic_cast<CRectangle*>(shape);
    sf::RectangleShape rectangleShape = rectangle->GetRectangleShape();
    
    if (rectangle)
    {
        window.draw(rectangleShape);

        if (rectangle->IsSelected())
        {
            sf::RectangleShape selectionRectangle;
            selectionRectangle.setPosition(sf::Vector2f(rectangleShape.getPosition().x, rectangleShape.getPosition().y));
            selectionRectangle.setSize(sf::Vector2f(rectangleShape.getSize().x, rectangleShape.getSize().y));
            selectionRectangle.setFillColor(sf::Color::Transparent);
            selectionRectangle.setOutlineThickness(2);
            selectionRectangle.setOutlineColor(sf::Color::Green);
            window.draw(selectionRectangle);

            // Рисование маркеров
            sf::CircleShape marker(5);
            marker.setFillColor(sf::Color::Green);
            marker.setPosition(sf::Vector2f(rectangleShape.getPosition().x - 5, rectangleShape.getPosition().y - 5));
            window.draw(marker);
            marker.setPosition(sf::Vector2f(rectangle->GetSecondPoint().x - 5, rectangleShape.getPosition().y - 5));
            window.draw(marker);
            marker.setPosition(sf::Vector2f(rectangleShape.getPosition().x - 5, rectangle->GetSecondPoint().y - 5));
            window.draw(marker);
            marker.setPosition(sf::Vector2f(rectangle->GetSecondPoint().x - 5, rectangle->GetSecondPoint().y - 5));
            window.draw(marker);
        }
    }
}
