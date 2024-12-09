#pragma once

#include "IShape.h"
#include "Command.h"
#include "ToolPanelManager.h"

class SetTypeColorCommand : public Command
{
public:
    SetTypeColorCommand(const ManagerToolPanel::TypeColor& typeColor) : m_typeColor(typeColor) {}

    void Execute() override;

private:
    ManagerToolPanel::TypeColor m_typeColor;
};