#include <iostream>
#include "ShapeHandler.h"
#include "Composite.h"
#include "ShapeReaderStateFactory.h"
#include "ShapeWriterStateFactory.h"
#include "ShapeDrawStateFactory.h"

void ShapeHandler::AddShape(std::shared_ptr<IShape> shape)
{
    m_shapes.push_back(shape);
}

void ShapeHandler::RemoveShape(std::shared_ptr<IShape> shape)
{
    std::vector<std::shared_ptr<IShape>>::iterator it = std::find(m_shapes.begin(), m_shapes.end(), shape);
    if (it != m_shapes.end())
    {
        m_shapes.erase(it);
    }
}

void ShapeHandler::ReadShapesFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    std::string line;
    ShapeReaderStateFactory factory;

    while (std::getline(file, line)) 
    {
        std::istringstream iss(line);
        std::string shapeType;
        iss >> shapeType;

        IShapeReaderState* state = factory.GetState(shapeType);

        if (state) 
        {
            std::shared_ptr<IShape> shape = state->ReadShape(iss);
            m_shapes.push_back(shape);
        }
    }
}

void ShapeHandler::WriteResultsToFile(const std::string& filename)
{
    std::ofstream file(filename);
    ShapeWriterStateFactory factory;

    for (const std::shared_ptr<IShape>& shape : m_shapes) 
    {
        IShapeWriterState* state = factory.GetState(shape->GetType());

        if (state) 
        {
            state->WriteShape(file, shape);
        }
    }
}

void ShapeHandler::SetThicknessCount()
{
    for (const std::shared_ptr<IShape> shape : m_shapes)
    {
        if (shape->IsSelected())
        {
            shape->SetThicknessCount(ToolPanelManager::GetInstance().GetOutlineThickness());
        }
    }
}

void ShapeHandler::SetFillColor(ManagerToolPanel::TypeColor& typeColor)
{
    for (const std::shared_ptr<IShape> shape : m_shapes)
    {
        if (shape->IsSelected())
        {
            switch (typeColor)
            {
            case ManagerToolPanel::FILL:
                shape->SetFillColor(ToolPanelManager::GetInstance().GetFillColor());
                break;
            case ManagerToolPanel::OUTLINE:
                shape->SetOutlineColor(ToolPanelManager::GetInstance().GetOutlineColor());
                break;
            default:
                break;
            }
        }
    }
}

void ShapeHandler::GroupSelectedShapesOnCtrlG()
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

void ShapeHandler::UngroupSelectedShapesOnCtrlU()
{
    for (const std::shared_ptr<IShape> shape : m_shapes)
    {
        if (shape->IsSelected())
        {
            if (shape->GetType() == Constants::TypeShape::COMPOSITE)
            {
                std::shared_ptr<Composite> composite = std::dynamic_pointer_cast<Composite>(shape);
                std::vector<std::shared_ptr<IShape>> children = composite->GetChildren();
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
        if (m_toolPanel.HandleEvent(event, window)) continue;

        m_state->HandleEvent(event, window, m_shapes);

        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed) 
        {
            if (event.key.code == sf::Keyboard::G && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) 
            {
                GroupSelectedShapesOnCtrlG();
            }
            else if (event.key.code == sf::Keyboard::U && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
            {
                UngroupSelectedShapesOnCtrlU();
            }
        }
    }
}

void ShapeHandler::DrawShapes(sf::RenderWindow& window) 
{
    ShapeDrawStateFactory factory;

    for (const std::shared_ptr<IShape> shape : m_shapes) 
    {
        IShapeDrawState* state = factory.GetState(shape->GetType());

        if (state)
        {
            state->DrawShape(window, shape);
        }
    }
}

void ShapeHandler::RenderLoop()
{
    sf::RenderWindow window(sf::VideoMode(Window::WIDTH, Window::HEIGHT), Window::NAME);

    while (window.isOpen())
    {
        WindowPollEvent(window);

        window.clear(sf::Color::Blue);

        DrawShapes(window);
        m_toolPanel.Draw(window);

        window.display();
    }
}

void ShapeHandler::HandleCommands()
{
    ReadShapesFromFile(Constants::FileName::INPUT_ROBOT);
    WriteResultsToFile(Constants::FileName::OUTPUT);
    RenderLoop();
}
