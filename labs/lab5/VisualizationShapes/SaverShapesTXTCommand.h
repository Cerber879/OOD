#pragma once

#include "IShape.h"
#include "Command.h"
#include "ToolPanelManager.h"

class SaverShapesTXTCommand : public Command
{
public:
    SaverShapesTXTCommand() {}

    void Execute() override;

};