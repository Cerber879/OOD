#include "FillingState.h"
#include "ToolPanelManager.h"

void FillingState::FillColor(sf::RenderWindow& window, std::vector<std::shared_ptr<IShape>>& shapes)
{
    sf::Vector2i position = sf::Mouse::getPosition(window);

    for (std::vector<std::shared_ptr<IShape>>::reverse_iterator itShape = shapes.rbegin(); itShape != shapes.rend(); ++itShape)
    {
        if ((*itShape)->Contains(position))
        {
            if ((*itShape)->ContainsFill(position))
            {
                sf::Color color = ToolPanelManager::GetInstance().GetFillColor();
                (*itShape)->SetFillColor(color);
            }
            else 
            {
                sf::Color color = ToolPanelManager::GetInstance().GetOutlineColor();
                (*itShape)->SetOutlineColor(color);
            }

            break;
        }
    }
}

void FillingState::MultiSelectShapesOnLShiftClick(sf::RenderWindow& window, std::vector<std::shared_ptr<IShape>>& shapes)
{
    sf::Vector2i position = sf::Mouse::getPosition(window);

    for (std::vector<std::shared_ptr<IShape>>::reverse_iterator itShape = shapes.rbegin(); itShape != shapes.rend(); ++itShape)
    {
        if ((*itShape)->Contains(position))
        {
            (*itShape)->SetSelected(true);
            break;
        }
    }
}

void FillingState::SingleSelectShapeOnMouseClick(sf::RenderWindow& window, std::vector<std::shared_ptr<IShape>>& shapes)
{
    sf::Vector2i position = sf::Mouse::getPosition(window);

    for (const std::shared_ptr<IShape> shape : shapes)
    {
        shape->SetSelected(false);
    }

    for (std::vector<std::shared_ptr<IShape>>::reverse_iterator itShape = shapes.rbegin(); itShape != shapes.rend(); ++itShape)
    {
        if ((*itShape)->Contains(position))
        {
            (*itShape)->SetSelected(true);
            break;
        }
    }
}

void FillingState::HandleEvent(sf::Event& event, sf::RenderWindow& window, std::vector<std::shared_ptr<IShape>>& shapes)
{
    switch (event.type)
    {
    case sf::Event::MouseButtonPressed:
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            FillColor(window, shapes);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            {
                MultiSelectShapesOnLShiftClick(window, shapes);
            }
            else
            {
                SingleSelectShapeOnMouseClick(window, shapes);
            }
        }
        break;
    }
    default:
        break;
    }
}
