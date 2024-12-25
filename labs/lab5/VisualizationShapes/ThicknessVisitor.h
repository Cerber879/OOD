#pragma once

#include "IShape.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CCircle.h"
#include "Composite.h"

class ThicknessVisitor : public IVisitor
{
public:
    ThicknessVisitor(float thickness) : m_thickness(thickness) {}

    void Visit(CRectangle& rectangle) override;
    void Visit(CTriangle& triangle) override;
    void Visit(CCircle& circle) override;
    void Visit(Composite& composite) override;

private:
    float m_thickness;
};
