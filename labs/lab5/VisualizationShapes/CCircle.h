#pragma once
#include "IShape.h"
#include "Constants.h"

class CCircle : public IShape 
{
    public:
        CCircle(const sf::Vector2f& center, const float radius, const sf::Color fillColor, const sf::Color outlineColor, const int thickness);
        CCircle();
        CCircle(sf::CircleShape& circleShape);

        void Accept(IVisitor& visitor) override;

        const sf::Vector2f GetPosition() const;
        const sf::Vector2f GetCenter() const;

        float GetRadius() const;

        std::string GetType() const override;
        bool Contains(sf::Vector2i position) const override;
        bool ContainsFill(sf::Vector2i position) const override;

        void SetFillColor(const sf::Color& color) override;
        sf::Color GetFillColor();

        void SetOutlineColor(const sf::Color& color);
        sf::Color GetOutlineColor();

        void SetThicknessCount(const int& count);
        int GetThicknessCount();

        sf::CircleShape GetCircleShape() const;

        bool Move(const sf::Vector2i& position) override;

        bool SetDragging(const bool isDragging) override;
        const bool IsDragging() const override;

        bool SetSelected(bool isSelected) override;
        const bool IsSelected() const override;

        const sf::FloatRect GetBoundingBox() const override;

        void SerializeTXT(std::ostream& stream) const override;
        void SerializeBIN(std::ostream& stream) const override;
        void DeserializeTXT(std::istream& stream) override;
        void DeserializeBIN(std::istream& stream) override;

    private:
        sf::CircleShape circle;

        sf::Vector2i m_offset;
        bool m_isDragging, m_isSelected;
 };
