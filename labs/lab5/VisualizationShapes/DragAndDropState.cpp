#include "DragAndDropState.h"
#include "ShapeHandler.h"

void DragAndDropState::MultiSelectShapesOnLShiftClick(sf::RenderWindow& window, std::vector<std::shared_ptr<IShape>>& shapes)
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

void DragAndDropState::SingleSelectShapeOnMouseClick(sf::RenderWindow& window, std::vector<std::shared_ptr<IShape>>& shapes)
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
            (*itShape)->SetDragging(true);

            m_prevPosition = position;
            break;
        }
    }
}

void DragAndDropState::ReleaseShapesOnMouseUp(sf::RenderWindow& window, std::vector<std::shared_ptr<IShape>>& shapes)
{
    for (const std::shared_ptr<IShape> shape : shapes)
    {
        if (shape->IsDragging())
        {
            sf::Vector2i position = sf::Mouse::getPosition(window);
            if (m_prevPosition - position != sf::Vector2i(0, 0))
            {
                Caretaker::GetInstance().Save(Memento(Momento::OperationType::MOVE, shape, m_prevPosition - position));
            }

            shape->SetDragging(false);
        }
    }
}

void DragAndDropState::DragSelectedShapesOnMouseMove(sf::RenderWindow& window, std::vector<std::shared_ptr<IShape>>& shapes)
{
    sf::Vector2i position = sf::Mouse::getPosition(window);

    for (const std::shared_ptr<IShape> shape : shapes)
    {
        if (shape->IsDragging())
        {
            shape->Move(position - m_lastPosition);
        }
    }
}

void DragAndDropState::HandleEvent(sf::Event& event, sf::RenderWindow& window, std::vector<std::shared_ptr<IShape>>& shapes)
{
    switch (event.type)
    {
        case sf::Event::MouseButtonPressed:
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
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
        case sf::Event::MouseButtonReleased:
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                ReleaseShapesOnMouseUp(window, shapes);
            }
            break;
        }
        case sf::Event::MouseMoved:
        {
            DragSelectedShapesOnMouseMove(window, shapes);
            m_lastPosition = sf::Mouse::getPosition(window);
            break;
        }
        default:
            break;
    }
}
