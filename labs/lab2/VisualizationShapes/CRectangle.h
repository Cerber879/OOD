#pragma once
#include "CShape.h"
#include "StringConstants.h"

class CRectangle : public CShape 
{
    public:
        CRectangle(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint);

        const sf::Vector2f GetFirstPoint() const;
        const sf::Vector2f GetSecondPoint() const;

        std::string GetType() const override;
        bool Contains(sf::Vector2i position) const override;

        sf::Vector2f GetSize() const;

        sf::RectangleShape GetRectangleShape() const;

        bool Move(const sf::Vector2i& position) override;

        bool SetDragging(const bool isDragging) override;
        const bool IsDragging() const override;

        bool SetSelected(bool isSelected) override;
        const bool IsSelected() const override;

        const sf::FloatRect GetBoundingBox() const override;

    private:
        sf::RectangleShape rectangle;

        sf::Vector2i m_offset;
        bool m_isDragging, m_isSelected;
};
