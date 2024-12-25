#include "ColorThicknessVisitor.h"

void ColorThicknessVisitor::Visit(CRectangle& rectangle)
{
    rectangle.SetOutlineColor(m_color);
}

void ColorThicknessVisitor::Visit(CTriangle& triangle)
{
    triangle.SetOutlineColor(m_color);
}

void ColorThicknessVisitor::Visit(CCircle& circle)
{
    circle.SetOutlineColor(m_color);
}

void ColorThicknessVisitor::Visit(Composite& composite)
{
    composite.SetOutlineColor(m_color);
}
