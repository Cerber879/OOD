#pragma once
#include "CShape.h"

class Composite : public CShape
{
    public:
        Composite(std::vector<std::shared_ptr<CShape>>& shapes) : 
            m_children(shapes), m_boundingBox(sf::FloatRect()), m_selected(false), m_dragging(false) {}

        Composite() : m_children(), m_boundingBox(sf::FloatRect()), m_selected(false), m_dragging(false) {}

        std::string GetType() const override;
        void Draw(sf::RenderWindow& window) const override;

        bool SetSelected(bool selected) override;
        const bool IsSelected() const override;

        bool SetDragging(bool dragging) override;
        const bool IsDragging() const override;

        bool Move(const sf::Vector2i& position) override;

        bool Contains(sf::Vector2i position) const override;

        void Add(std::shared_ptr<CShape> component);
        void Remove(std::shared_ptr<CShape> component) override;
        std::vector<std::shared_ptr<CShape>> GetChildren() const override;
        const sf::FloatRect GetBoundingBox() const override;

    private:
        void DrawBackground(sf::RenderWindow& window) const;
        void DrawBoundingBox(sf::RenderWindow& window) const;

        sf::FloatRect CombineBoundingBoxes(const sf::FloatRect& a, const sf::FloatRect& b) const;


        std::vector<std::shared_ptr<CShape>> m_children;
        sf::FloatRect m_boundingBox;
        bool m_selected, m_dragging;
};
