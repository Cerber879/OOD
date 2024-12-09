#include "Composite.h"
#include "CRectangleDrawDecorator.h"
#include "CCircleDrawDecorator.h"
#include "CTriangleDrawDecorator.h"
#include "ShapeDrawStateFactory.h"

std::string Composite::GetType() const
{
    return "COMPOSITE";
}

void Composite::DrawBoundingBox(sf::RenderWindow& window) const
{
    sf::RectangleShape selectionComposite(sf::Vector2f(m_boundingBox.width, m_boundingBox.height));
    selectionComposite.setPosition(m_boundingBox.left, m_boundingBox.top);
    selectionComposite.setFillColor(sf::Color::Transparent);
    selectionComposite.setOutlineThickness(2);
    selectionComposite.setOutlineColor(sf::Color::Green);
    window.draw(selectionComposite);

    // Рисование маркеров
    sf::CircleShape marker(5);
    marker.setFillColor(sf::Color::Green);
    marker.setPosition(sf::Vector2f(selectionComposite.getPosition().x - 5, selectionComposite.getPosition().y - 5));
    window.draw(marker);
    marker.setPosition(sf::Vector2f((selectionComposite.getPosition() + selectionComposite.getSize()).x - 5, selectionComposite.getPosition().y - 5));
    window.draw(marker);
    marker.setPosition(sf::Vector2f(selectionComposite.getPosition().x - 5, (selectionComposite.getPosition() + selectionComposite.getSize()).y - 5));
    window.draw(marker);
    marker.setPosition(sf::Vector2f((selectionComposite.getPosition() + selectionComposite.getSize()).x - 5, (selectionComposite.getPosition() + selectionComposite.getSize()).y - 5));
    window.draw(marker);
}

void Composite::DrawBackground(sf::RenderWindow& window) const
{
    sf::RectangleShape background(sf::Vector2f(m_boundingBox.width, m_boundingBox.height));
    background.setPosition(m_boundingBox.left, m_boundingBox.top);
    background.setFillColor(sf::Color::White);
    window.draw(background);
}

void Composite::Draw(sf::RenderWindow& window) const 
{
    DrawBackground(window);

    ShapeDrawStateFactory factory;

    for (const std::shared_ptr<IShape> children : m_children)
    {
        IShapeDrawState* state = factory.GetState(children->GetType());

        if (state)
        {
            state->DrawShape(window, children);
        }
    }

    if (IsSelected())
    {
        DrawBoundingBox(window);
    }
}

void Composite::SetFillColor(const sf::Color& color)
{
    for (const std::shared_ptr<IShape> children : m_children)
    {
        children->SetFillColor(color);
    }
}

void Composite::SetOutlineColor(const sf::Color& color)
{
    for (const std::shared_ptr<IShape> children : m_children)
    {
        children->SetOutlineColor(color);
    }
}

void Composite::SetThicknessCount(const int& count)
{
    for (const std::shared_ptr<IShape> children : m_children)
    {
        children->SetThicknessCount(count);
    }
}

bool Composite::SetSelected(bool selected)
{
    m_selected = selected;
    return true;
}

const bool Composite::IsSelected() const 
{
    return m_selected;
}

bool Composite::SetDragging(bool dragging)
{
    m_dragging = dragging;
    for (const auto& child : m_children)
    {
        child->SetDragging(dragging);
    }

    return false;
}

const bool Composite::IsDragging() const
{
    return m_dragging;
}

bool Composite::Move(const sf::Vector2i& offset)
{
    for (const auto& child : m_children) 
    {
        child->Move(offset);
    }

    m_boundingBox.left += offset.x;
    m_boundingBox.top += offset.y;

    return true;
}

bool Composite::Contains(sf::Vector2i position) const
{
    sf::Vector2i secondPoint(m_boundingBox.left + m_boundingBox.width, m_boundingBox.top + m_boundingBox.height);

    if (position.x >= m_boundingBox.left && position.y >= m_boundingBox.top &&
        position.x <= secondPoint.x && position.y <= secondPoint.y)
    {
        return true;
    }

    return false;
}

void Composite::Add(std::shared_ptr<IShape> component)
{
    if (m_children.empty())
    {
        m_boundingBox = component->GetBoundingBox();
    }
    else
    {
        m_boundingBox = CombineBoundingBoxes(m_boundingBox, component->GetBoundingBox());
    }

    m_children.push_back(component);
}

void Composite::Remove(std::shared_ptr<IShape> component) 
{
    m_children.erase(std::remove(m_children.begin(), m_children.end(), component), m_children.end());
}

std::vector<std::shared_ptr<IShape>> Composite::GetChildren() const 
{
    return m_children;
}

const sf::FloatRect Composite::GetBoundingBox() const
{
    return m_boundingBox;
}

sf::FloatRect Composite::CombineBoundingBoxes(const sf::FloatRect& a, const sf::FloatRect& b) const
{
    float left = std::min(a.left, b.left);
    float top = std::min(a.top, b.top);
    float right = std::max(a.left + a.width, b.left + b.width);
    float bottom = std::max(a.top + a.height, b.top + b.height);\

    return sf::FloatRect(left, top, right - left, bottom - top);
}