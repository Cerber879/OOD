#include "SetModeCommand.h"
#include "ShapeHandler.h"
#include "FillingState.h"

void SetModeCommand::Execute()
{
    switch(m_mode)
    {
        case ManagerToolPanel::TypeMode::DRAG_AND_DROP:
            ShapeHandler::GetInstance().SetState(std::make_shared<DragAndDropState>());
            break;
        case ManagerToolPanel::TypeMode::FILLING:
            ShapeHandler::GetInstance().SetState(std::make_shared<FillingState>());
            break;
        default:
            break;
    }
}
