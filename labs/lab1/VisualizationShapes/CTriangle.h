#pragma once
#include "CShape.h"
#include "StringConstants.h"

class CTriangle : public CShape 
{
    public:
        CTriangle(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint, const sf::Vector2f& thirdPoint);

        std::string GetType() const override;

        const double GetLengthSide(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint) const;
        const double GetFirstSize() const;
        const double GetSecondSize() const;
        const double GetThirdSize() const;

        sf::ConvexShape GetConvexShape() const;

    private:
        sf::ConvexShape triangle;
};