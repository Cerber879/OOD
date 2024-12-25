#include "Composite.h"
#include "CRectangleDrawDecorator.h"
#include "CCircleDrawDecorator.h"
#include "CTriangleDrawDecorator.h"
#include "ShapeDrawStateFactory.h"
#include "ColorVisitor.h"
#include "ColorThicknessVisitor.h"
#include "ThicknessVisitor.h"

std::string Composite::GetType() const
{
    return "COMPOSITE";
}

void Composite::Accept(IVisitor& visitor)
{
    visitor.Visit(*this);
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
        ColorVisitor colorVisitor(color);
        children->Accept(colorVisitor);
    }
}

void Composite::SetOutlineColor(const sf::Color& color)
{
    for (const std::shared_ptr<IShape> children : m_children)
    {
        ColorThicknessVisitor colorVisitor(color);
        children->Accept(colorVisitor);
    }
}

sf::Color Composite::GetFillColor()
{
    return m_children[0]->GetFillColor();
}

void Composite::SetThicknessCount(const int& count)
{
    for (const std::shared_ptr<IShape> children : m_children)
    {
        ThicknessVisitor colorVisitor(count);
        children->Accept(colorVisitor);
    }
}

bool Composite::SetSelected(bool selected)
{
    m_selected = selected;
    return true;
}

sf::Color Composite::GetOutlineColor()
{
    return m_children[0]->GetOutlineColor();
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

int Composite::GetThicknessCount()
{
    return m_children[0]->GetThicknessCount();
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


void Composite::SerializeTXT(std::ostream& stream) const 
{
    stream << "Composite "
        << m_boundingBox.left << " "
        << m_boundingBox.top << " "
        << m_boundingBox.width << " "
        << m_boundingBox.height << " "
        << m_children.size() << " ";

    for (const auto& child : m_children) 
    {
        child->SerializeTXT(stream);
    }
}

void Composite::SerializeBIN(std::ostream& stream) const 
{
    stream.write(reinterpret_cast<const char*>(&m_boundingBox.left), sizeof(m_boundingBox.left));
    stream.write(reinterpret_cast<const char*>(&m_boundingBox.top), sizeof(m_boundingBox.top));
    stream.write(reinterpret_cast<const char*>(&m_boundingBox.width), sizeof(m_boundingBox.width));
    stream.write(reinterpret_cast<const char*>(&m_boundingBox.height), sizeof(m_boundingBox.height));

    size_t size = m_children.size();
    stream.write(reinterpret_cast<const char*>(&size), sizeof(size));

    for (const auto& child : m_children)
    {
        child->SerializeBIN(stream);
    }
}

void Composite::DeserializeTXT(std::istream& stream) 
{
    float left, top, width, height;
    size_t size;

    if (!(stream >> left >> top >> width >> height >> size))
    {
        throw std::runtime_error("Failed to read Composite data from stream");
    }

    m_boundingBox = sf::FloatRect(left, top, width, height);
    m_children.clear();

    for (size_t i = 0; i < size; ++i) 
    {
        auto child = CreateShapeFromType(stream);
        if (child) 
        {
            child->DeserializeTXT(stream);
            m_children.push_back(child);
        }
        else 
        {
            throw std::runtime_error("Failed to create child shape from stream");
        }
    }
}

void Composite::DeserializeBIN(std::istream& stream) 
{
    stream.read(reinterpret_cast<char*>(&m_boundingBox.left), sizeof(m_boundingBox.left));
    stream.read(reinterpret_cast<char*>(&m_boundingBox.top), sizeof(m_boundingBox.top));
    stream.read(reinterpret_cast<char*>(&m_boundingBox.width), sizeof(m_boundingBox.width));
    stream.read(reinterpret_cast<char*>(&m_boundingBox.height), sizeof(m_boundingBox.height));

    size_t size;
    stream.read(reinterpret_cast<char*>(&size), sizeof(size));

    m_children.clear();

    for (size_t i = 0; i < size; ++i) 
    {
        auto child = CreateShapeFromType(stream);
        if (child) 
        {
            child->DeserializeBIN(stream);
            m_children.push_back(child);
        }
        else 
        {
            throw std::runtime_error("Failed to create child shape from stream");
        }
    }
}

std::shared_ptr<IShape> Composite::CreateShapeFromType(std::istream& stream) 
{
    std::string type;
    stream >> type;

    if (type == "Circle") 
    {
        return std::make_shared<CCircle>();
    }
    else if (type == "Rectangle") 
    {
        return std::make_shared<CRectangle>();
    }
    else if (type == "Triangle") 
    {
        return std::make_shared<CTriangle>();
    }
    else if (type == "Composite")
    {
        return std::make_shared<Composite>();
    }

    return nullptr;
}