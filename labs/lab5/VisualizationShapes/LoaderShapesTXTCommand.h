#pragma once

#include "IShape.h"
#include "Command.h"
#include "ToolPanelManager.h"

class LoaderShapesTXTCommand : public Command
{
public:
    LoaderShapesTXTCommand() {}

    void Execute() override;

};