#include "CTriangle.h"

CTriangle::CTriangle(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint, const sf::Vector2f& thirdPoint)
{
    triangle.setPointCount(THREE);
    triangle.setPoint(0, firstPoint);
    triangle.setPoint(1, secondPoint);
    triangle.setPoint(TWO, thirdPoint);
}

std::string CTriangle::GetType() const
{
    return TRIANGLE;
}

const double CTriangle::GetLengthSide(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint) const
{
    return std::sqrt(std::pow(firstPoint.x - secondPoint.x, TWO) + std::pow(firstPoint.y - secondPoint.y, TWO));
}

const double CTriangle::GetFirstSize() const
{
    return GetLengthSide(triangle.getPoint(0), triangle.getPoint(1));
}

const double CTriangle::GetSecondSize() const
{
    return GetLengthSide(triangle.getPoint(1), triangle.getPoint(2));
}

const double CTriangle::GetThirdSize() const
{
    return GetLengthSide(triangle.getPoint(2), triangle.getPoint(0));
}

sf::ConvexShape CTriangle::GetConvexShape() const
{
    return triangle;
}
