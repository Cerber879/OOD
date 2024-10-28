#include "CShape.h"

std::string CShape::GetType() const
{
    return std::string();
}

bool CShape::Contains(sf::Vector2i position) const
{
    return false;
}

bool CShape::SetDragging(const bool isDragging)
{
    return false;
}

const bool CShape::IsDragging() const
{
    return false;
}

bool CShape::SetSelected(bool selected)
{
    return false;
}

const bool CShape::IsSelected() const
{
    return false;
}

const sf::FloatRect CShape::GetBoundingBox() const
{
    return sf::FloatRect();
}

void CShape::Draw(sf::RenderWindow& window) const
{
}

bool CShape::Move(const sf::Vector2i& position)
{
    return false;
}

void CShape::Add(std::shared_ptr<CShape> component)
{
}

void CShape::Remove(std::shared_ptr<CShape> component)
{
}

std::vector<std::shared_ptr<CShape>> CShape::GetChildren() const
{
    return std::vector<std::shared_ptr<CShape>>();
}
