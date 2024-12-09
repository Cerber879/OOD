#include "CRectangle.h"

CRectangle::CRectangle(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint, const sf::Color fillColor, const sf::Color outlineColor, const int thickness)
{
    rectangle.setPosition(firstPoint);
    rectangle.setSize(sf::Vector2f(std::abs(firstPoint.x - secondPoint.x), std::abs(firstPoint.y - secondPoint.y)));
    rectangle.setFillColor(fillColor);
    rectangle.setOutlineColor(outlineColor);
    rectangle.setOutlineThickness(thickness);

    m_isSelected = false;
    m_offset = sf::Vector2i(0, 0);
    m_isDragging = false;
}

void CRectangle::Accept(IVisitor& visitor)
{
    visitor.Visit(*this);
}

const sf::Vector2f CRectangle::GetFirstPoint() const
{
    return rectangle.getPosition();
}

const sf::Vector2f CRectangle::GetSecondPoint() const
{
    return rectangle.getPosition() + rectangle.getSize();
}

std::string CRectangle::GetType() const
{
    return Constants::TypeShape::RECTANGLE;
}

sf::Vector2f CRectangle::GetSize() const
{
    return rectangle.getSize();
}

sf::RectangleShape CRectangle::GetRectangleShape() const
{
    return rectangle;
}

bool CRectangle::Contains(sf::Vector2i position) const
{
    return rectangle.getGlobalBounds().contains(position.x, position.y);
}

bool CRectangle::ContainsFill(sf::Vector2i position) const
{
    int outlineThickness = rectangle.getOutlineThickness();
    sf::FloatRect bounds = rectangle.getGlobalBounds();
    sf::FloatRect innerBounds(bounds.left + outlineThickness, bounds.top + outlineThickness,
        bounds.width - 2 * outlineThickness, bounds.height - 2 * outlineThickness);

    return innerBounds.contains(position.x, position.y);
}

void CRectangle::SetFillColor(const sf::Color& color)
{
    rectangle.setFillColor(color);
}

sf::Color CRectangle::GetFillColor()
{
    return rectangle.getFillColor();
}

void CRectangle::SetOutlineColor(const sf::Color& color)
{
    rectangle.setOutlineColor(color);
}

sf::Color CRectangle::GetOutlineColor()
{
    return rectangle.getOutlineColor();
}

void CRectangle::SetThicknessCount(const int& count)
{
    rectangle.setOutlineThickness(count);
}

int CRectangle::GetThicknessCount()
{
    return rectangle.getOutlineThickness();
}

bool CRectangle::Move(const sf::Vector2i& offset)
{
    rectangle.setPosition(rectangle.getPosition().x + offset.x, rectangle.getPosition().y + offset.y);
    return true;
}

bool CRectangle::SetDragging(const bool isDragging)
{
    m_isDragging = isDragging;
    return true;
}

const bool CRectangle::IsDragging() const
{
    return m_isDragging;
}

bool CRectangle::SetSelected(bool isSelected)
{
    m_isSelected = isSelected;
    return true;
}

const bool CRectangle::IsSelected() const
{
    return m_isSelected;
}

const sf::FloatRect CRectangle::GetBoundingBox() const
{
    return rectangle.getGlobalBounds();
}