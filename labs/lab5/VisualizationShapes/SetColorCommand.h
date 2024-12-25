#pragma once

#include "IShape.h"
#include "Command.h"
#include "ToolPanelManager.h"

class SetColorCommand : public Command 
{
public:
    SetColorCommand(const sf::Color& color) : m_color(color) {}

    void Execute() override;

private:
    sf::Color m_color;
};