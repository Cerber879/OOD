#include "Memento.h"

Momento::OperationType Memento::GetType() const
{
    return m_type;
}

std::vector<std::shared_ptr<IShape>> Memento::GetShapes() const
{
    return m_shapes;
}

std::shared_ptr<IShape> Memento::GetShape() const
{
    return m_shape;
}

sf::Vector2i Memento::GetOffset() const
{
    return m_offset;
}

sf::Color Memento::GetColor() const
{
    return m_color;
}

int Memento::GetThickness() const
{
    return m_thickness;
}
