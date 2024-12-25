#pragma once

#include "IShape.h"
#include "Command.h"
#include "ToolPanelManager.h"

class SetOutlineThicknessCommand : public Command
{
public:
    SetOutlineThicknessCommand(int thickness) : m_thickness(thickness) {}

    void Execute() override;

private:
    int m_thickness;
};