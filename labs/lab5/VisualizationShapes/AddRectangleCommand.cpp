#include "AddRectangleCommand.h"
#include "ShapeHandler.h"

void AddRectangleCommand::Execute()
{
    std::shared_ptr<CRectangle> shape = std::make_shared<CRectangle>
        (
            Constants::StartPositionRectangleShape::firstPoint,
            Constants::StartPositionRectangleShape::secondPoint,
            ToolPanelManager::GetInstance().GetFillColor(),
            ToolPanelManager::GetInstance().GetOutlineColor(),
            ToolPanelManager::GetInstance().GetOutlineThickness()
        );

    Caretaker::GetInstance().Save(Memento(Momento::OperationType::ADD, shape));
    ShapeHandler::GetInstance().AddShape(shape);
}