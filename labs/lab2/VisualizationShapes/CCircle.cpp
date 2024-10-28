#include "CCircle.h"

CCircle::CCircle(const sf::Vector2f& center, float radius)
{
    circle.setRadius(radius);
    circle.setPosition(center.x - radius, center.y - radius);
    circle.setFillColor(sf::Color::Cyan);

    m_isSelected = false;
    m_isDragging = false;
}

const sf::Vector2f CCircle::GetCenter() const
{
    return circle.getPosition() + sf::Vector2f(circle.getRadius(), circle.getRadius());
}

const sf::Vector2f CCircle::GetPosition() const
{
    return circle.getPosition();
}

std::string CCircle::GetType() const
{
    return CIRCLE;
}

float CCircle::GetRadius() const
{
    return circle.getRadius();
}

sf::CircleShape CCircle::GetCircleShape() const
{
    return circle;
}

bool CCircle::Contains(sf::Vector2i position) const
{
    sf::Vector2f center = circle.getPosition() + sf::Vector2f(circle.getRadius(), circle.getRadius());
    float distance = std::sqrt(std::pow(position.x - center.x, 2) + std::pow(position.y - center.y, 2));
    return distance <= circle.getRadius();
}

bool CCircle::Move(const sf::Vector2i& offset)
{
    circle.setPosition(circle.getPosition().x + offset.x, circle.getPosition().y + offset.y);
    return true;
}

bool CCircle::SetDragging(const bool isDragging)
{
    m_isDragging = isDragging;
    return true;
}

const bool CCircle::IsDragging() const
{
    return m_isDragging;
}

bool CCircle::SetSelected(bool isSelected)
{
    m_isSelected = isSelected;
    return true;
}

const bool CCircle::IsSelected() const
{
    return m_isSelected;
}

const sf::FloatRect CCircle::GetBoundingBox() const
{
    return circle.getGlobalBounds();
}