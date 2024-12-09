#include "SetOutlineThicknessCommand.h"
#include "ShapeHandler.h"

void SetOutlineThicknessCommand::Execute()
{
	ToolPanelManager::GetInstance().SetOutlineThickness(m_thickness);
	ShapeHandler::GetInstance().SetThicknessCount();
}