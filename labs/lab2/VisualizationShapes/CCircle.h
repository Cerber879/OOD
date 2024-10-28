#pragma once
#include "CShape.h"
#include "StringConstants.h"

class CCircle : public CShape 
{
    public:
        CCircle(const sf::Vector2f& center, float radius);

        const sf::Vector2f GetPosition() const;
        const sf::Vector2f GetCenter() const;

        std::string GetType() const override;
        bool Contains(sf::Vector2i position) const override;

        float GetRadius() const;

        sf::CircleShape GetCircleShape() const;

        bool Move(const sf::Vector2i& position) override;

        bool SetDragging(const bool isDragging) override;
        const bool IsDragging() const override;

        bool SetSelected(bool isSelected) override;
        const bool IsSelected() const override;

        const sf::FloatRect GetBoundingBox() const override;

    private:
        sf::CircleShape circle;

        sf::Vector2i m_offset;
        bool m_isDragging, m_isSelected;
 };
