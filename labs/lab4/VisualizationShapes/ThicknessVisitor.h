#pragma once

#include "IShape.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CCircle.h"

class ThicknessVisitor : public IVisitor
{
public:
    ThicknessVisitor(float thickness) : m_thickness(thickness) {}

    void Visit(CRectangle& rectangle) override;
    void Visit(CTriangle& triangle) override;
    void Visit(CCircle& circle) override;

private:
    float m_thickness;
};
