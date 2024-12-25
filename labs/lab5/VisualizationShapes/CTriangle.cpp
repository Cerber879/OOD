#include "CTriangle.h"

CTriangle::CTriangle(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint, const sf::Vector2f& thirdPoint, const sf::Color fillColor, const sf::Color outlineColor, const int thickness)
{
    triangle.setPointCount(Constants::Number::THREE);
    triangle.setPoint(0, firstPoint);
    triangle.setPoint(1, secondPoint);
    triangle.setPoint(Constants::Number::TWO, thirdPoint);
    triangle.setFillColor(fillColor);
    triangle.setOutlineColor(outlineColor);
    triangle.setOutlineThickness(thickness);

    m_isSelected = false;
    m_isDragging = false;
}

CTriangle::CTriangle()
{
    triangle.setPointCount(Constants::Number::THREE);
    m_isSelected = false;
    m_isDragging = false;
}

CTriangle::CTriangle(sf::ConvexShape& convexShape)
{
    triangle = convexShape;
    m_isSelected = false;
    m_isDragging = false;
}

void CTriangle::Accept(IVisitor& visitor)
{
    visitor.Visit(*this);
}

std::string CTriangle::GetType() const
{
    return Constants::TypeShape::TRIANGLE;
}

const sf::Vector2f CTriangle::GetPoint(int index) const
{
    if (index < 0 || index >= 3)
    {
        throw std::out_of_range(Constants::ErrorText::POINT_OUT_OF_RANGE);
    }

    return triangle.getPoint(index);
}

const float CTriangle::GetLengthSide(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint) const
{
    return std::sqrt(std::pow(firstPoint.x - secondPoint.x, Constants::Number::TWO) + std::pow(firstPoint.y - secondPoint.y, Constants::Number::TWO));
}

const float CTriangle::GetSize(int firstPoint, int secondPoint) const
{
    return GetLengthSide(GetPoint(firstPoint), GetPoint(secondPoint));
}

sf::ConvexShape CTriangle::GetConvexShape() const
{
    return triangle;
}

float CTriangle::Sign(const sf::Vector2i& firstPoint, const sf::Vector2f& secondPoint, const sf::Vector2f& thirdPoint) const
{
    return (firstPoint.x - thirdPoint.x) * (secondPoint.y - thirdPoint.y) - (secondPoint.x - thirdPoint.x) * (firstPoint.y - thirdPoint.y);
}

bool CTriangle::Contains(sf::Vector2i position) const
{
    return triangle.getGlobalBounds().contains(position.x, position.y);
}

bool CTriangle::ContainsFill(sf::Vector2i position) const
{
    float d1, d2, d3;
    bool has_neg, has_pos;

    d1 = Sign(position, triangle.getPoint(0), triangle.getPoint(1));
    d2 = Sign(position, triangle.getPoint(1), triangle.getPoint(2));
    d3 = Sign(position, triangle.getPoint(2), triangle.getPoint(0));

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(has_neg && has_pos);
}

void CTriangle::SetFillColor(const sf::Color& color)
{
    triangle.setFillColor(color);
}

sf::Color CTriangle::GetFillColor()
{
    return triangle.getFillColor();
}

void CTriangle::SetOutlineColor(const sf::Color& color)
{
    triangle.setOutlineColor(color);
}

sf::Color CTriangle::GetOutlineColor()
{
    return triangle.getOutlineColor();
}

void CTriangle::SetThicknessCount(const int& count)
{
    triangle.setOutlineThickness(count);
}

int CTriangle::GetThicknessCount()
{
    return triangle.getOutlineThickness();
}

bool CTriangle::Move(const sf::Vector2i& offset)
{
    triangle.setPoint(0, triangle.getPoint(0) + sf::Vector2f(offset));
    triangle.setPoint(1, triangle.getPoint(1) + sf::Vector2f(offset));
    triangle.setPoint(2, triangle.getPoint(2) + sf::Vector2f(offset));

    return true;
}

bool CTriangle::SetDragging(const bool isDragging)
{
    m_isDragging = isDragging;
    return true;
}

const bool CTriangle::IsDragging() const
{
    return m_isDragging;
}

bool CTriangle::SetSelected(bool isSelected)
{
    m_isSelected = isSelected;
    return true;
}

const bool CTriangle::IsSelected() const
{
    return m_isSelected;
}

const sf::FloatRect CTriangle::GetBoundingBox() const
{
    return triangle.getGlobalBounds();
}

void CTriangle::SerializeTXT(std::ostream& stream) const 
{
    for (size_t i = 0; i < 3; ++i) {
        stream << GetType() << " "
            << triangle.getPoint(i).x << " "
            << triangle.getPoint(i).y << " ";
    }
    stream << triangle.getFillColor().toInteger() << " "
        << triangle.getOutlineColor().toInteger() << " "
        << triangle.getOutlineThickness() << " ";
}

void CTriangle::DeserializeTXT(std::istream& stream)
{
    sf::Vector2f points[3];
    sf::Uint32 fillColorInt, outlineColorInt;
    float outlineThickness;

    for (size_t i = 0; i < 3; ++i)
    {
        if (!(stream >> points[i].x >> points[i].y)) 
        {
            throw std::runtime_error("Failed to read point data from stream");
        }
    }

    if (!(stream >> fillColorInt >> outlineColorInt >> outlineThickness))
    {
        throw std::runtime_error("Failed to read color and thickness data from stream");
    }

    sf::Color fillColor = sf::Color(fillColorInt);
    sf::Color outlineColor = sf::Color(outlineColorInt);

    triangle.setPointCount(3);
    for (size_t i = 0; i < 3; ++i)
    {
        triangle.setPoint(i, points[i]);
    }
    triangle.setFillColor(fillColor);
    triangle.setOutlineColor(outlineColor);
    triangle.setOutlineThickness(outlineThickness);
}

void CTriangle::SerializeBIN(std::ostream& stream) const
{
    sf::Vector2f points[3];
    for (size_t i = 0; i < 3; ++i)
    {
        points[i] = triangle.getPoint(i);
    }
    auto fillColor = triangle.getFillColor().toInteger();
    auto outlineColor = triangle.getOutlineColor().toInteger();
    auto outlineThickness = triangle.getOutlineThickness();

    for (size_t i = 0; i < 3; ++i) 
    {
        stream.write(reinterpret_cast<const char*>(&points[i].x), sizeof(points[i].x));
        stream.write(reinterpret_cast<const char*>(&points[i].y), sizeof(points[i].y));
    }
    stream.write(reinterpret_cast<const char*>(&fillColor), sizeof(fillColor));
    stream.write(reinterpret_cast<const char*>(&outlineColor), sizeof(outlineColor));
    stream.write(reinterpret_cast<const char*>(&outlineThickness), sizeof(outlineThickness));
}


void CTriangle::DeserializeBIN(std::istream& stream) 
{
    sf::Vector2f points[3];
    sf::Uint32 fillColorInt, outlineColorInt;
    float outlineThickness;

    for (size_t i = 0; i < 3; ++i) 
    {
        stream.read(reinterpret_cast<char*>(&points[i].x), sizeof(points[i].x));
        stream.read(reinterpret_cast<char*>(&points[i].y), sizeof(points[i].y));
    }
    stream.read(reinterpret_cast<char*>(&fillColorInt), sizeof(fillColorInt));
    stream.read(reinterpret_cast<char*>(&outlineColorInt), sizeof(outlineColorInt));
    stream.read(reinterpret_cast<char*>(&outlineThickness), sizeof(outlineThickness));

    sf::Color fillColor = sf::Color(fillColorInt);
    sf::Color outlineColor = sf::Color(outlineColorInt);

    triangle.setPointCount(3);
    for (size_t i = 0; i < 3; ++i) 
    {
        triangle.setPoint(i, points[i]);
    }
    triangle.setFillColor(fillColor);
    triangle.setOutlineColor(outlineColor);
    triangle.setOutlineThickness(outlineThickness);
}
