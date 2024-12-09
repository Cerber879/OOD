#pragma once

#include "IShape.h"

class IToolPanelState
{
public:
    virtual ~IToolPanelState() = default;
    virtual void HandleEvent(sf::Event& event, sf::RenderWindow& window, std::vector<std::shared_ptr<IShape>>& shapes) = 0;
};