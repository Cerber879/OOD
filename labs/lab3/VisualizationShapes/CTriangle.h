#pragma once
#include "IShape.h"
#include "Constants.h"

class CTriangle : public IShape 
{
    public:
        CTriangle(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint, const sf::Vector2f& thirdPoint, const sf::Color fillColor, const sf::Color outlineColor, const int thickness);

        const sf::Vector2f GetPoint(int index) const;

        const float GetLengthSide(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint) const;
        const float GetSize(int firstPoint, int secondPoint) const;

        std::string GetType() const override;
        bool Contains(sf::Vector2i position) const override;
        bool ContainsFill(sf::Vector2i position) const override;

        void SetFillColor(const sf::Color& color) override;
        void SetOutlineColor(const sf::Color& color) override;
        void SetThicknessCount(const int& count) override;

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