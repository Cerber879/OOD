#pragma once
#include "CShape.h"
#include "StringConstants.h"

class CCircle : public CShape 
{
    public:
        CCircle(const sf::Vector2f& center, double radius);

        std::string GetType() const override;

        double GetRadius() const;

        sf::CircleShape GetCircleShape() const;

    private:
        sf::CircleShape circle;
 };
