#pragma once

#include "IShape.h"
#include "Command.h"
#include "ToolPanelManager.h"

class SaverShapesBINCommand : public Command
{
public:
    SaverShapesBINCommand() {}

    void Execute() override;

};