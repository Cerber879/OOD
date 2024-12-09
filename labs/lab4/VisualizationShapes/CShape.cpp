#include "IShape.h"

std::string IShape::GetType() const
{
    return std::string();
}

void IShape::Accept(IVisitor& visitor)
{
}

bool IShape::Contains(sf::Vector2i position) const
{
    return false;
}

bool IShape::ContainsFill(sf::Vector2i position) const
{
    return false;
}

bool IShape::SetDragging(const bool isDragging)
{
    return false;
}

const bool IShape::IsDragging() const
{
    return false;
}

bool IShape::SetSelected(bool selected)
{
    return false;
}

const bool IShape::IsSelected() const
{
    return false;
}

const sf::FloatRect IShape::GetBoundingBox() const
{
    return sf::FloatRect();
}

void IShape::SetFillColor(const sf::Color& color)
{
}

sf::Color IShape::GetFillColor()
{
    return sf::Color();
}

void IShape::SetOutlineColor(const sf::Color& color)
{
}

sf::Color IShape::GetOutlineColor()
{
    return sf::Color();
}

void IShape::SetThicknessCount(const int& count)
{
}

int IShape::GetThicknessCount()
{
    return 0;
}

void IShape::Draw(sf::RenderWindow& window) const
{
}

bool IShape::Move(const sf::Vector2i& position)
{
    return false;
}

void IShape::Add(std::shared_ptr<IShape> component)
{
}

void IShape::Remove(std::shared_ptr<IShape> component)
{
}

std::vector<std::shared_ptr<IShape>> IShape::GetChildren() const
{
    return std::vector<std::shared_ptr<IShape>>();
}
