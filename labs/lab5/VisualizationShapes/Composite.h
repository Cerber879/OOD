#pragma once
#include "IShape.h"

class Composite : public IShape
{
    public:
        Composite(std::vector<std::shared_ptr<IShape>>& shapes) : 
            m_children(shapes), m_boundingBox(sf::FloatRect()), m_selected(false), m_dragging(false) {}

        Composite(sf::FloatRect& boundingBox) :
            m_children(), m_boundingBox(boundingBox), m_selected(false), m_dragging(false) {}

        Composite() : m_children(), m_boundingBox(sf::FloatRect()), m_selected(false), m_dragging(false) {}

        void Accept(IVisitor& visitor);

        std::string GetType() const override;
        void Draw(sf::RenderWindow& window) const override;

        void SetFillColor(const sf::Color& color) override;
        sf::Color GetFillColor();

        void SetOutlineColor(const sf::Color& color);
        sf::Color GetOutlineColor();

        void SetThicknessCount(const int& count);
        int GetThicknessCount();

        bool SetSelected(bool selected) override;
        const bool IsSelected() const override;

        bool SetDragging(bool dragging) override;
        const bool IsDragging() const override;

        bool Move(const sf::Vector2i& position) override;

        bool Contains(sf::Vector2i position) const override;

        void Add(std::shared_ptr<IShape> component);
        void Remove(std::shared_ptr<IShape> component) override;
        std::vector<std::shared_ptr<IShape>> GetChildren() const override;
        void SetChildren(std::vector<std::shared_ptr<IShape>>& children) { m_children = children; }
        const sf::FloatRect GetBoundingBox() const override;

        void SerializeTXT(std::ostream& stream) const override;
        void SerializeBIN(std::ostream& stream) const override;
        void DeserializeTXT(std::istream& stream) override;
        void DeserializeBIN(std::istream& stream) override;
        std::shared_ptr<IShape> CreateShapeFromType(std::istream& stream);


    private:
        void DrawBackground(sf::RenderWindow& window) const;
        void DrawBoundingBox(sf::RenderWindow& window) const;

        sf::FloatRect CombineBoundingBoxes(const sf::FloatRect& a, const sf::FloatRect& b) const;


        std::vector<std::shared_ptr<IShape>> m_children;
        sf::FloatRect m_boundingBox;
        bool m_selected, m_dragging;
};
