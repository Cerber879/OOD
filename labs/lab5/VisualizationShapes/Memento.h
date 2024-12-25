#pragma once

#include <memory>
#include <vector>
#include "IShape.h"

class Memento 
{
public:
    Memento(Momento::OperationType type, const std::vector<std::shared_ptr<IShape>>& shapes)
        : m_type(type), m_shapes(shapes), m_thickness(0) {}

    Memento(Momento::OperationType type, const std::shared_ptr<IShape>& shape)
        : m_type(type), m_shape(shape), m_thickness(0) {}

    Memento(Momento::OperationType type, const std::shared_ptr<IShape>& shape, const sf::Vector2i& offset)
        : m_type(type), m_shape(shape), m_offset(offset), m_thickness(0) {}

    Memento(Momento::OperationType type, const std::shared_ptr<IShape>& shape, const sf::Color& color)
        : m_type(type), m_shape(shape), m_color(color), m_thickness(0) {}

    Memento(Momento::OperationType type, const std::shared_ptr<IShape>& shape, const int& thickness)
        : m_type(type), m_shape(shape), m_thickness(thickness) {}

    Memento() : m_type(Momento::OperationType::NULLPTR), m_shape(nullptr), m_thickness(0) {}

    Momento::OperationType GetType() const;
    std::vector<std::shared_ptr<IShape>> GetShapes() const;
    std::shared_ptr<IShape> GetShape() const;
    sf::Vector2i GetOffset() const;
    sf::Color GetColor() const;
    int GetThickness() const;

private:
    std::vector<std::shared_ptr<IShape>> m_shapes;
    std::shared_ptr<IShape> m_shape;

    Momento::OperationType m_type;
    sf::Vector2i m_offset;
    sf::Color m_color;
    int m_thickness;
};
