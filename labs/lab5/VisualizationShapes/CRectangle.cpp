#include "CRectangle.h"

CRectangle::CRectangle(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint, const sf::Color fillColor, const sf::Color outlineColor, const int thickness)
{
    rectangle.setPosition(firstPoint);
    rectangle.setSize(sf::Vector2f(std::abs(firstPoint.x - secondPoint.x), std::abs(firstPoint.y - secondPoint.y)));
    rectangle.setFillColor(fillColor);
    rectangle.setOutlineColor(outlineColor);
    rectangle.setOutlineThickness(thickness);

    m_isSelected = false;
    m_offset = sf::Vector2i(0, 0);
    m_isDragging = false;
}

CRectangle::CRectangle()
{
    m_isSelected = false;
    m_offset = sf::Vector2i(0, 0);
    m_isDragging = false;
}

CRectangle::CRectangle(sf::RectangleShape& rectangleShape)
{
    rectangle = rectangleShape;
    m_isSelected = false;
    m_offset = sf::Vector2i(0, 0);
    m_isDragging = false;
}

void CRectangle::Accept(IVisitor& visitor)
{
    visitor.Visit(*this);
}

const sf::Vector2f CRectangle::GetFirstPoint() const
{
    return rectangle.getPosition();
}

const sf::Vector2f CRectangle::GetSecondPoint() const
{
    return rectangle.getPosition() + rectangle.getSize();
}

std::string CRectangle::GetType() const
{
    return Constants::TypeShape::RECTANGLE;
}

sf::Vector2f CRectangle::GetSize() const
{
    return rectangle.getSize();
}

sf::RectangleShape CRectangle::GetRectangleShape() const
{
    return rectangle;
}

bool CRectangle::Contains(sf::Vector2i position) const
{
    return rectangle.getGlobalBounds().contains(position.x, position.y);
}

bool CRectangle::ContainsFill(sf::Vector2i position) const
{
    int outlineThickness = rectangle.getOutlineThickness();
    sf::FloatRect bounds = rectangle.getGlobalBounds();
    sf::FloatRect innerBounds(bounds.left + outlineThickness, bounds.top + outlineThickness,
        bounds.width - 2 * outlineThickness, bounds.height - 2 * outlineThickness);

    return innerBounds.contains(position.x, position.y);
}

void CRectangle::SetFillColor(const sf::Color& color)
{
    rectangle.setFillColor(color);
}

sf::Color CRectangle::GetFillColor()
{
    return rectangle.getFillColor();
}

void CRectangle::SetOutlineColor(const sf::Color& color)
{
    rectangle.setOutlineColor(color);
}

sf::Color CRectangle::GetOutlineColor()
{
    return rectangle.getOutlineColor();
}

void CRectangle::SetThicknessCount(const int& count)
{
    rectangle.setOutlineThickness(count);
}

int CRectangle::GetThicknessCount()
{
    return rectangle.getOutlineThickness();
}

bool CRectangle::Move(const sf::Vector2i& offset)
{
    rectangle.setPosition(rectangle.getPosition().x + offset.x, rectangle.getPosition().y + offset.y);
    return true;
}

bool CRectangle::SetDragging(const bool isDragging)
{
    m_isDragging = isDragging;
    return true;
}

const bool CRectangle::IsDragging() const
{
    return m_isDragging;
}

bool CRectangle::SetSelected(bool isSelected)
{
    m_isSelected = isSelected;
    return true;
}

const bool CRectangle::IsSelected() const
{
    return m_isSelected;
}

const sf::FloatRect CRectangle::GetBoundingBox() const
{
    return rectangle.getGlobalBounds();
}


void CRectangle::SerializeTXT(std::ostream& stream) const 
{
    stream << GetType() << " "
        << rectangle.getSize().x << " "
        << rectangle.getSize().y << " "
        << rectangle.getFillColor().toInteger() << " "
        << rectangle.getOutlineColor().toInteger() << " "
        << rectangle.getOutlineThickness() << " "
        << rectangle.getPosition().x << " "
        << rectangle.getPosition().y << " ";
}

void CRectangle::DeserializeTXT(std::istream& stream) 
{
    float width, height;
    sf::Uint32 fillColorInt, outlineColorInt;
    float outlineThickness;
    float positionX, positionY;

    if (!(stream >> width >> height >> fillColorInt >> outlineColorInt >> outlineThickness >> positionX >> positionY))
    {
        throw std::runtime_error("Failed to read data from stream");
    }

    sf::Color fillColor = sf::Color(fillColorInt);
    sf::Color outlineColor = sf::Color(outlineColorInt);

    rectangle.setSize(sf::Vector2f(width, height));
    rectangle.setFillColor(fillColor);
    rectangle.setOutlineColor(outlineColor);
    rectangle.setOutlineThickness(outlineThickness);
    rectangle.setPosition(positionX, positionY);
}

void CRectangle::SerializeBIN(std::ostream& stream) const
{
    auto size = rectangle.getSize();
    auto fillColor = rectangle.getFillColor().toInteger();
    auto outlineColor = rectangle.getOutlineColor().toInteger();
    auto outlineThickness = rectangle.getOutlineThickness();
    auto position = rectangle.getPosition();

    stream.write(reinterpret_cast<const char*>(&size.x), sizeof(size.x));
    stream.write(reinterpret_cast<const char*>(&size.y), sizeof(size.y));
    stream.write(reinterpret_cast<const char*>(&fillColor), sizeof(fillColor));
    stream.write(reinterpret_cast<const char*>(&outlineColor), sizeof(outlineColor));
    stream.write(reinterpret_cast<const char*>(&outlineThickness), sizeof(outlineThickness));
    stream.write(reinterpret_cast<const char*>(&position.x), sizeof(position.x));
    stream.write(reinterpret_cast<const char*>(&position.y), sizeof(position.y));
}

void CRectangle::DeserializeBIN(std::istream& stream)
{
    float width, height;
    sf::Uint32 fillColorInt, outlineColorInt;
    float outlineThickness;
    float positionX, positionY;

    stream.read(reinterpret_cast<char*>(&width), sizeof(width));
    stream.read(reinterpret_cast<char*>(&height), sizeof(height));
    stream.read(reinterpret_cast<char*>(&fillColorInt), sizeof(fillColorInt));
    stream.read(reinterpret_cast<char*>(&outlineColorInt), sizeof(outlineColorInt));
    stream.read(reinterpret_cast<char*>(&outlineThickness), sizeof(outlineThickness));
    stream.read(reinterpret_cast<char*>(&positionX), sizeof(positionX));
    stream.read(reinterpret_cast<char*>(&positionY), sizeof(positionY));

    sf::Color fillColor = sf::Color(fillColorInt);
    sf::Color outlineColor = sf::Color(outlineColorInt);

    rectangle.setSize(sf::Vector2f(width, height));
    rectangle.setFillColor(fillColor);
    rectangle.setOutlineColor(outlineColor);
    rectangle.setOutlineThickness(outlineThickness);
    rectangle.setPosition(positionX, positionY);
}
