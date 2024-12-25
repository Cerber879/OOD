#include "AddCircleCommand.h"
#include "ShapeHandler.h"
#include "ToolPanelManager.h"

void AddCircleCommand::Execute()
{
    std::shared_ptr<CCircle> shape = std::make_shared<CCircle>
        (
            Constants::StartPositionCircleShape::centerPoint,
            Constants::StartPositionCircleShape::radius,
            ToolPanelManager::GetInstance().GetFillColor(),
            ToolPanelManager::GetInstance().GetOutlineColor(),
            ToolPanelManager::GetInstance().GetOutlineThickness()
        );

    Caretaker::GetInstance().Save(Memento(Momento::OperationType::ADD, shape));
    ShapeHandler::GetInstance().AddShape(shape);
}