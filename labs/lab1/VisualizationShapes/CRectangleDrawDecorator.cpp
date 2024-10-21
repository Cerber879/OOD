#include "CRectangleDrawDecorator.h"
#include "CRectangle.h"

std::string CRectangleDrawDecorator::GetType() const
{
    return RECTANGLE;
}

void CRectangleDrawDecorator::Draw(sf::RenderWindow& window) const
{
    CRectangle* rectangle = dynamic_cast<CRectangle*>(shape);
    if (rectangle)
    {
        window.draw(rectangle->GetRectangleShape());
    }
}
