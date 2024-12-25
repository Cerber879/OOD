#include "ThicknessVisitor.h"

void ThicknessVisitor::Visit(CRectangle& rectangle)
{
    rectangle.SetThicknessCount(m_thickness);
}

void ThicknessVisitor::Visit(CTriangle& triangle)
{
    triangle.SetThicknessCount(m_thickness);
}

void ThicknessVisitor::Visit(CCircle& circle)
{
    circle.SetThicknessCount(m_thickness);
}

void ThicknessVisitor::Visit(Composite& composite)
{
    composite.SetThicknessCount(m_thickness);
}
