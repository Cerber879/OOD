#pragma once
#include "IShape.h"
#include "Constants.h"

class CRectangle : public IShape 
{
    public:
        CRectangle(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint, const sf::Color fillColor, const sf::Color outlineColor, const int thickness);

        void Accept(IVisitor& visitor) override;

        const sf::Vector2f GetFirstPoint() const;
        const sf::Vector2f GetSecondPoint() const;

        sf::Vector2f GetSize() const;

        std::string GetType() const override;
        bool Contains(sf::Vector2i position) const override;
        bool ContainsFill(sf::Vector2i position) const override;

        void SetFillColor(const sf::Color& color) override;
        sf::Color GetFillColor();

        void SetOutlineColor(const sf::Color& color);
        sf::Color GetOutlineColor();

        void SetThicknessCount(const int& count);
        int GetThicknessCount();

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
