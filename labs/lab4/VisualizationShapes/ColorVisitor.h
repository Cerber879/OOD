#pragma once

#include "IShape.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CCircle.h"

class ColorVisitor : public IVisitor 
{
public:
    ColorVisitor(const sf::Color& color) : m_color(color) {}

    void Visit(CRectangle& rectangle) override;
    void Visit(CTriangle& triangle) override;
    void Visit(CCircle& circle) override;

private:
    sf::Color m_color;
};