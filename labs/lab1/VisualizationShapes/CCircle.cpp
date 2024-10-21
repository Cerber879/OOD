#include "CCircle.h"

CCircle::CCircle(const sf::Vector2f& center, double radius)
{
    circle.setRadius(radius);
    circle.setPosition(center.x - radius, center.y - radius);
}

std::string CCircle::GetType() const
{
    return CIRCLE;
}

double CCircle::GetRadius() const
{
    return circle.getRadius();
}

sf::CircleShape CCircle::GetCircleShape() const
{
    return circle;
}
