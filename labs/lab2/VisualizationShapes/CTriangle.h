#pragma once
#include "CShape.h"
#include "StringConstants.h"

class CTriangle : public CShape 
{
    public:
        CTriangle(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint, const sf::Vector2f& thirdPoint);

        const sf::Vector2f GetPoint(int index) const;

        std::string GetType() const override;
        bool Contains(sf::Vector2i position) const override;

        const float GetLengthSide(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint) const;
        const float GetSize(int firstPoint, int secondPoint) const;

        sf::ConvexShape GetConvexShape() const;

        bool Move(const sf::Vector2i& position) override;

        bool SetDragging(const bool isDragging) override;
        const bool IsDragging() const override;

        bool SetSelected(bool isSelected) override;
        const bool IsSelected() const override;

        const sf::FloatRect GetBoundingBox() const override;

    private:
        float Sign(const sf::Vector2i& firstPoint, const sf::Vector2f& secondPoint, const sf::Vector2f& thirdPoint) const;

        sf::ConvexShape triangle;

        sf::Vector2i m_offset;
        sf::Vector2f m_topLeftCorner;
        bool m_isDragging, m_isSelected;
};