#include "ShapeHandler.h"
#include "Composite.h"
#include <iostream>

void ShapeHandler::ReadShapesFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string shapeType;
        iss >> shapeType;

        if (shapeType == STR_PREFIX_TRIANGLE)
        {
            CTriangleFileDecorator triangle;
            std::shared_ptr<CShape> shape = triangle.ReadShape(iss);
            m_shapes.push_back(shape);
        }
        else if (shapeType == STR_PREFIX_RECTANGLE)
        {
            CRectangleFileDecorator rectangle;
            std::shared_ptr<CShape> shape = rectangle.ReadShape(iss);
            m_shapes.push_back(shape);
        }
        else if (shapeType == STR_PREFIX_CIRCLE)
        {
            CCircleFileDecorator circle;
            std::shared_ptr<CShape> shape = circle.ReadShape(iss);
            m_shapes.push_back(shape);
        }
    }
}

void ShapeHandler::WriteResultsToFile(const std::string& filename)
{
    std::ofstream file(filename);

    for (const std::shared_ptr<CShape>& shape : m_shapes)
    {
        if (shape->GetType() == RECTANGLE)
        {
            CRectangleFileDecorator rectangle(shape.get());
            file << rectangle.WriteShape(shape);
        }
        else if (shape->GetType() == CIRCLE)
        {
            CCircleFileDecorator circle(shape.get());
            file << circle.WriteShape(shape);
        }
        else if (shape->GetType() == TRIANGLE)
        {
            CTriangleFileDecorator triangle(shape.get());
            file << triangle.WriteShape(shape);
        }
    }
}

void ShapeHandler::MouseLeftButtonPressedWithLShift(sf::RenderWindow& window)
{
    sf::Vector2i position = sf::Mouse::getPosition(window);

    for (std::vector<std::shared_ptr<CShape>>::reverse_iterator itShape = m_shapes.rbegin(); itShape != m_shapes.rend(); ++itShape)
    {
        if ((*itShape)->Contains(position))
        {
            (*itShape)->SetSelected(true);
            (*itShape)->SetDragging(true);
            break;
        }
    }
}

void ShapeHandler::MouseLeftButtonPressed(sf::RenderWindow& window)
{
    sf::Vector2i position = sf::Mouse::getPosition(window);

    for (const std::shared_ptr<CShape> shape : m_shapes)
    {
        shape->SetSelected(false);
    }

    for (std::vector<std::shared_ptr<CShape>>::reverse_iterator itShape = m_shapes.rbegin(); itShape != m_shapes.rend(); ++itShape)
    {
        if ((*itShape)->Contains(position))
        {
            (*itShape)->SetSelected(true);
            (*itShape)->SetDragging(true);
            break;
        }
    }
}

void ShapeHandler::MouseLeftButtonReleased()
{
    for (const std::shared_ptr<CShape> shape : m_shapes)
    {
        shape->SetDragging(false);
    }
}

void ShapeHandler::MouseLeftButtonMoved(sf::RenderWindow& window)
{
    sf::Vector2i position = sf::Mouse::getPosition(window);

    for (const std::shared_ptr<CShape> shape : m_shapes)
    {
        if (shape->IsDragging())
        {
            shape->Move(position - m_lastPosition);
        }
    }
}

void ShapeHandler::KeyGWithLControlPressed()
{
    std::shared_ptr<Composite> group = std::make_shared<Composite>();

    for (auto itShape = m_shapes.begin(); itShape != m_shapes.end();)
    {
        if ((*itShape)->IsSelected())
        {
            group->Add(*itShape);
            (*itShape)->SetSelected(false);
            itShape = m_shapes.erase(itShape);
        }
        else
        {
            ++itShape;
        }
    }

    if (!group->GetChildren().empty())
    {
        group->SetSelected(true);
        m_shapes.push_back(group);
    }
}

void ShapeHandler::KeyUWithLControlPressed()
{
    for (const std::shared_ptr<CShape> shape : m_shapes)
    {
        if (shape->IsSelected())
        {
            if (shape->GetType() == COMPOSITE)
            {
                std::shared_ptr<Composite> composite = std::dynamic_pointer_cast<Composite>(shape);
                std::vector<std::shared_ptr<CShape>> children = composite->GetChildren();
                m_shapes.erase(std::remove(m_shapes.begin(), m_shapes.end(), shape), m_shapes.end());
                m_shapes.insert(m_shapes.end(), children.begin(), children.end());
            }
        }
    }
}

void ShapeHandler::WindowPollEvent(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) 
                {
                    MouseLeftButtonPressedWithLShift(window);
                }
                else 
                {
                    MouseLeftButtonPressed(window);
                }

                m_lastPosition = sf::Mouse::getPosition(window);
            }
        }
        else if (event.type == sf::Event::MouseButtonReleased)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                MouseLeftButtonReleased();
            }
        }
        else if (event.type == sf::Event::MouseMoved)
        {
            MouseLeftButtonMoved(window);
            m_lastPosition = sf::Mouse::getPosition(window);
        }
        else if (event.type == sf::Event::KeyPressed) 
        {
            if (event.key.code == sf::Keyboard::G && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) 
            {
                KeyGWithLControlPressed();
            }
            else if (event.key.code == sf::Keyboard::U && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
            {
                KeyUWithLControlPressed();
            }
        }
    }
}

void ShapeHandler::DrawShapes(sf::RenderWindow& window)
{
    for (const std::shared_ptr<CShape> shape : m_shapes)
    {
        if (shape->GetType() == RECTANGLE)
        {
            CRectangleDrawDecorator rectangle(shape.get());
            rectangle.Draw(window);
        }
        else if (shape->GetType() == CIRCLE)
        {
            CCircleDrawDecorator circle(shape.get());
            circle.Draw(window);
        }
        else if (shape->GetType() == TRIANGLE)
        {
            CTriangleDrawDecorator triangle(shape.get());
            triangle.Draw(window);
        }
        else if (shape->GetType() == COMPOSITE)
        {
            shape->Draw(window);
        }
    }
}

void ShapeHandler::RenderLoop()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Geometric shapes");

    while (window.isOpen())
    {
        WindowPollEvent(window);

        window.clear(sf::Color::Blue);

        DrawShapes(window);

        window.display();
    }
}

void ShapeHandler::HandleCommands()
{
    ReadShapesFromFile(INPUT);
    WriteResultsToFile(OUTPUT);
    RenderLoop();
}
