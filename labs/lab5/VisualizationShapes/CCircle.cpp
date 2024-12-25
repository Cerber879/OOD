#include "CCircle.h"

CCircle::CCircle(const sf::Vector2f& center, const float radius, const sf::Color fillColor, const sf::Color outlineColor, const int thickness)
{
    circle.setRadius(radius);
    circle.setPosition(center.x - radius, center.y - radius);
    circle.setFillColor(fillColor);
    circle.setOutlineColor(outlineColor);
    circle.setOutlineThickness(thickness);

    m_isSelected = false;
    m_isDragging = false;
}

CCircle::CCircle()
{
    m_isSelected = false;
    m_isDragging = false;
}

CCircle::CCircle(sf::CircleShape& cirlceShape)
{
    circle = cirlceShape;
    m_isSelected = false;
    m_isDragging = false;
}


void CCircle::Accept(IVisitor& visitor)
{
    visitor.Visit(*this);
}

const sf::Vector2f CCircle::GetCenter() const
{
    return circle.getPosition() + sf::Vector2f(circle.getRadius(), circle.getRadius());
}

const sf::Vector2f CCircle::GetPosition() const
{
    return circle.getPosition();
}

std::string CCircle::GetType() const
{
    return Constants::TypeShape::CIRCLE;
}

float CCircle::GetRadius() const
{
    return circle.getRadius();
}

sf::CircleShape CCircle::GetCircleShape() const
{
    return circle;
}

bool CCircle::Contains(sf::Vector2i position) const
{
    return circle.getGlobalBounds().contains(position.x, position.y);
}

bool CCircle::ContainsFill(sf::Vector2i position) const
{
    sf::Vector2f center = circle.getPosition() + sf::Vector2f(circle.getRadius(), circle.getRadius());
    float distance = std::sqrt(std::pow(position.x - center.x, 2) + std::pow(position.y - center.y, 2));
    return distance <= circle.getRadius();
}

void CCircle::SetFillColor(const sf::Color& color)
{
    circle.setFillColor(color);
}

sf::Color CCircle::GetFillColor()
{
    return circle.getFillColor();
}

void CCircle::SetOutlineColor(const sf::Color& color)
{
    circle.setOutlineColor(color);
}

sf::Color CCircle::GetOutlineColor()
{
    return circle.getOutlineColor();
}

void CCircle::SetThicknessCount(const int& count)
{
    circle.setOutlineThickness(count);
}

int CCircle::GetThicknessCount()
{
    return circle.getOutlineThickness();
}

bool CCircle::Move(const sf::Vector2i& offset)
{
    circle.setPosition(circle.getPosition().x + offset.x, circle.getPosition().y + offset.y);
    return true;
}

bool CCircle::SetDragging(const bool isDragging)
{
    m_isDragging = isDragging;
    return true;
}

const bool CCircle::IsDragging() const
{
    return m_isDragging;
}

bool CCircle::SetSelected(bool isSelected)
{
    m_isSelected = isSelected;
    return true;
}

const bool CCircle::IsSelected() const
{
    return m_isSelected;
}

const sf::FloatRect CCircle::GetBoundingBox() const
{
    return circle.getGlobalBounds();
}


void CCircle::SerializeTXT(std::ostream& stream) const 
{
    stream << GetType() << " "
        << circle.getRadius() << " "
        << circle.getFillColor().toInteger() << " "
        << circle.getOutlineColor().toInteger() << " "
        << circle.getOutlineThickness() << " "
        << circle.getPosition().x << " "
        << circle.getPosition().y << " ";
}

void CCircle::SerializeBIN(std::ostream& stream) const
{
    auto radius = circle.getRadius();
    auto fillColor = circle.getFillColor().toInteger();
    auto outlineColor = circle.getOutlineColor().toInteger();
    auto outlineThickness = circle.getOutlineThickness();
    auto position = circle.getPosition();

    stream.write(reinterpret_cast<const char*>(&radius), sizeof(radius));
    stream.write(reinterpret_cast<const char*>(&fillColor), sizeof(fillColor));
    stream.write(reinterpret_cast<const char*>(&outlineColor), sizeof(outlineColor));
    stream.write(reinterpret_cast<const char*>(&outlineThickness), sizeof(outlineThickness));
    stream.write(reinterpret_cast<const char*>(&position.x), sizeof(position.x));
    stream.write(reinterpret_cast<const char*>(&position.y), sizeof(position.y));
}

void CCircle::DeserializeTXT(std::istream& stream) 
{
    float radius;
    sf::Uint32 fillColorInt, outlineColorInt;
    float outlineThickness;
    float positionX, positionY;

    if (!(stream >> radius >> fillColorInt >> outlineColorInt >> outlineThickness >> positionX >> positionY)) 
    {
        throw std::runtime_error("Failed to read data from stream");
    }

    sf::Color fillColor = sf::Color(fillColorInt);
    sf::Color outlineColor = sf::Color(outlineColorInt);

    circle.setRadius(radius);
    circle.setFillColor(fillColor);
    circle.setOutlineColor(outlineColor);
    circle.setOutlineThickness(outlineThickness);
    circle.setPosition(positionX, positionY);
}

void CCircle::DeserializeBIN(std::istream& stream)
{
    decltype(circle.getRadius()) radius;
    sf::Uint32 fillColorInt;
    sf::Uint32 outlineColorInt;
    decltype(circle.getOutlineThickness()) outlineThickness;
    decltype(circle.getPosition().x) x;
    decltype(circle.getPosition().y) y;

    stream.read(reinterpret_cast<char*>(&radius), sizeof(radius));
    stream.read(reinterpret_cast<char*>(&fillColorInt), sizeof(fillColorInt));
    stream.read(reinterpret_cast<char*>(&outlineColorInt), sizeof(outlineColorInt));
    stream.read(reinterpret_cast<char*>(&outlineThickness), sizeof(outlineThickness));
    stream.read(reinterpret_cast<char*>(&x), sizeof(x));
    stream.read(reinterpret_cast<char*>(&y), sizeof(y));

    sf::Color fillColor = sf::Color(fillColorInt);
    sf::Color outlineColor = sf::Color(outlineColorInt);

    circle.setRadius(radius);
    circle.setFillColor(fillColor);
    circle.setOutlineColor(outlineColor);
    circle.setOutlineThickness(outlineThickness);
    circle.setPosition({ x, y });
}
