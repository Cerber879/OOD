#include "ColorVisitor.h"

void ColorVisitor::Visit(CRectangle& rectangle) 
{
    rectangle.SetFillColor(m_color);
}

void ColorVisitor::Visit(CTriangle& triangle) 
{
    triangle.SetFillColor(m_color);
}

void ColorVisitor::Visit(CCircle& circle) 
{
    circle.SetFillColor(m_color);
}