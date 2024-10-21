#include "CTriangleDrawDecorator.h"
#include "CTriangle.h"

std::string CTriangleDrawDecorator::GetType() const
{
    return TRIANGLE;
}

void CTriangleDrawDecorator::Draw(sf::RenderWindow& window) const
{
    CTriangle* convex = dynamic_cast<CTriangle*>(shape);
    if (convex)
    {
        window.draw(convex->GetConvexShape());
    }
}
