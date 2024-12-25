#pragma once

#pragma once

#include "IShape.h"
#include "Command.h"
#include "ToolPanelManager.h"

class LoaderShapesBINCommand : public Command
{
public:
    LoaderShapesBINCommand() {}

    void Execute() override;

};