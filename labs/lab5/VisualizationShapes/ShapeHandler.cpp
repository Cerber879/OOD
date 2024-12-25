#include <iostream>
#include "ShapeHandler.h"
#include "Composite.h"
#include "ShapeReaderStateFactory.h"
#include "ShapeWriterStateFactory.h"
#include "ShapeDrawStateFactory.h"
#include "ColorVisitor.h"
#include "ColorThicknessVisitor.h"
#include "ThicknessVisitor.h"

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
            Caretaker::GetInstance().Save(Memento(Momento::OperationType::CHANGE_THICKNESS, shape, shape->GetThicknessCount()));
            ThicknessVisitor colorVisitor(ToolPanelManager::GetInstance().GetOutlineThickness());
            shape->Accept(colorVisitor);
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
                {
                    Caretaker::GetInstance().Save(Memento(Momento::OperationType::CHANGE_COLOR, shape, shape->GetFillColor()));
                    ColorVisitor colorVisitor(ToolPanelManager::GetInstance().GetFillColor());
                    shape->Accept(colorVisitor);
                    break;
                }
                case ManagerToolPanel::OUTLINE:
                {
                    Caretaker::GetInstance().Save(Memento(Momento::OperationType::CHANGE_COLOR_THICKNESS, shape, shape->GetOutlineColor()));
                    ColorThicknessVisitor colorVisitor(ToolPanelManager::GetInstance().GetOutlineColor());
                    shape->Accept(colorVisitor);
                    break;
                }
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

    Caretaker::GetInstance().Save(Memento(Momento::OperationType::GROUP, group));
}

void ShapeHandler::UngroupSelectedShapesOnCtrlU()
{
    std::vector<std::shared_ptr<IShape>> shapesToUngroup;

    for (const std::shared_ptr<IShape>& shape : m_shapes)
    {
        if (shape->IsSelected() && shape->GetType() == Constants::TypeShape::COMPOSITE)
        {
            shapesToUngroup.push_back(shape);
        }
    }

    for (const std::shared_ptr<IShape>& shape : shapesToUngroup)
    {
        std::shared_ptr<Composite> composite = std::dynamic_pointer_cast<Composite>(shape);
        std::vector<std::shared_ptr<IShape>> children = composite->GetChildren();
        m_shapes.erase(std::remove(m_shapes.begin(), m_shapes.end(), shape), m_shapes.end());
        m_shapes.insert(m_shapes.end(), children.begin(), children.end());

        Caretaker::GetInstance().Save(Memento(Momento::OperationType::UNGROUP, composite));
    }
}


void ShapeHandler::Undo()
{
    Memento memento = m_caretaker.Undo();

    if (memento.GetType() == Momento::OperationType::NULLPTR)
    {
        return;
    }

    switch (memento.GetType())
    {
        case Momento::OperationType::INSERT_INTO_FILE:
        {
            std::vector<std::shared_ptr<IShape>> shapes = memento.GetShapes();
            SetShapes(shapes);
            break;
        }
        case Momento::OperationType::ADD:
        {
            std::shared_ptr<IShape> shape = memento.GetShape();
            RemoveShape(shape);
            break;
        }
        case Momento::OperationType::REMOVE:
        {
            AddShape(memento.GetShape());
            break;
        }
        case Momento::OperationType::MOVE:
        {
            memento.GetShape()->Move(memento.GetOffset());
            break;
        }
        case Momento::OperationType::CHANGE_COLOR:
        {
            memento.GetShape()->SetFillColor(memento.GetColor());
            break;
        }
        case Momento::OperationType::CHANGE_COLOR_THICKNESS:
        {
            memento.GetShape()->SetOutlineColor(memento.GetColor());
            break;
        }
        case Momento::OperationType::CHANGE_THICKNESS:
        {
            ThicknessVisitor thicknessVisitor(memento.GetThickness());
            memento.GetShape()->Accept(thicknessVisitor);
            break;
        }
        case Momento::OperationType::GROUP:
        {
            RemoveShape(memento.GetShape());
            for (const std::shared_ptr<IShape>& shape : memento.GetShape()->GetChildren()) 
            {
                AddShape(shape);
            }
            break;
        }
        case Momento::OperationType::UNGROUP:
        {
            for (const std::shared_ptr<IShape>& shape : memento.GetShape()->GetChildren())
            {
                RemoveShape(shape);
            }
            AddShape(memento.GetShape());
            break;
        }
        default:
            break;
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
            else if (event.key.code == sf::Keyboard::Z && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
            {
                Undo();
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
    ReadShapesFromFile(Constants::FileName::CURRENT_FILE);
    WriteResultsToFile(Constants::FileName::OUTPUT);
    RenderLoop();
}
