#pragma once
#include "CShape.h"
#include "StringConstants.h"

class CRectangle : public CShape 
{
    public:
        CRectangle(const sf::Vector2f& firstPoint, const sf::Vector2f& secondPoint);

        std::string GetType() const override;

        sf::Vector2f GetSize() const;

        sf::RectangleShape GetRectangleShape() const;

    private:
        sf::RectangleShape rectangle;
};
