#include "SetTypeColorCommand.h"

void SetTypeColorCommand::Execute()
{
	ToolPanelManager::GetInstance().SetColorType(m_typeColor);
}
