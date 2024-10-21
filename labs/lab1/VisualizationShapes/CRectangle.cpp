#include "CRectangle.h"

CRectangle::CRectangle(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint)
{
    rectangle.setPosition(firstPoint);
    rectangle.setSize(sf::Vector2f(std::abs(firstPoint.x - secondPoint.x), std::abs(firstPoint.y - secondPoint.y)));
    rectangle.setFillColor(sf::Color::Green);
}

std::string CRectangle::GetType() const
{
    return RECTANGLE;
}

sf::Vector2f CRectangle::GetSize() const
{
    return rectangle.getSize();
}

sf::RectangleShape CRectangle::GetRectangleShape() const
{
    return rectangle;
}
