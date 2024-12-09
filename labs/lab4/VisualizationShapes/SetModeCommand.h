#pragma once

#include "IShape.h"
#include "Command.h"
#include "ToolPanelManager.h"

class SetModeCommand : public Command
{
public:
    SetModeCommand(const ManagerToolPanel::TypeMode& mode) : m_mode(mode) {}

    void Execute() override;

private:
    ManagerToolPanel::TypeMode m_mode;
};