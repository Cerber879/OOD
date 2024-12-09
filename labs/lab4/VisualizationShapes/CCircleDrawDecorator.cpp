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
            sf::FloatRect boundingBox = circle->GetBoundingBox();

            // ������� ������������� �����
            sf::RectangleShape selectionRectangle;
            selectionRectangle.setSize(sf::Vector2f(boundingBox.width, boundingBox.height));
            selectionRectangle.setPosition(sf::Vector2f(boundingBox.left, boundingBox.top));
            selectionRectangle.setFillColor(sf::Color::Transparent);
            selectionRectangle.setOutlineThickness(2);
            selectionRectangle.setOutlineColor(sf::Color::Green);
            window.draw(selectionRectangle);

            // ��������� �������� �� ����� �����
            sf::CircleShape marker(5);
            marker.setFillColor(sf::Color::Green);

            // ������� ����� ����
            marker.setPosition(sf::Vector2f(boundingBox.left - 5, boundingBox.top - 5));
            window.draw(marker);

            // ������� ������ ����
            marker.setPosition(sf::Vector2f(boundingBox.left + boundingBox.width - 5, boundingBox.top - 5));
            window.draw(marker);

            // ������ ����� ����
            marker.setPosition(sf::Vector2f(boundingBox.left - 5, boundingBox.top + boundingBox.height - 5));
            window.draw(marker);

            // ������ ������ ����
            marker.setPosition(sf::Vector2f(boundingBox.left + boundingBox.width - 5, boundingBox.top + boundingBox.height - 5));
            window.draw(marker);
        }
    }
}
