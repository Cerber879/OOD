#include "CCircleDrawDecorator.h"
#include "CCircle.h"

std::string CCircleDrawDecorator::GetType() const
{
    return CIRCLE;
}

void CCircleDrawDecorator::Draw(sf::RenderWindow& window) const
{
    CCircle* circle = dynamic_cast<CCircle*>(shape);
    if (circle)
    {
        window.draw(circle->GetCircleShape());
    }
}
