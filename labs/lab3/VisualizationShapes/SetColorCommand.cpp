#include "SetColorCommand.h"
#include "ShapeHandler.h"

void SetColorCommand::Execute()
{
    ManagerToolPanel::TypeColor typeColor = ToolPanelManager::GetInstance().GetColorType();

	switch (typeColor)
	{
		case ManagerToolPanel::FILL:
		{
			ToolPanelManager::GetInstance().SetFillColor(m_color);
			ToolPanel::GetInstance().GetFillColorButton()->SetColor(m_color);
			break;
		}
		case ManagerToolPanel::OUTLINE:
		{
			ToolPanelManager::GetInstance().SetOutlineColor(m_color);
			ToolPanel::GetInstance().GetOutlineColorButton()->SetColor(m_color);
			break;
		}
		default:
			break;
	}

	ShapeHandler::GetInstance().SetFillColor(typeColor);

}