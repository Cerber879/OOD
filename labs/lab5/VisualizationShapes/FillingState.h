#pragma once

#include "IShape.h"
#include "IToolPanelState.h"

class FillingState : public IToolPanelState
{
public:
    void HandleEvent(sf::Event& event, sf::RenderWindow& window, std::vector<std::shared_ptr<IShape>>& shapes) override;

private:
    void FillColor(sf::RenderWindow& window, std::vector<std::shared_ptr<IShape>>& shapes);

    void MultiSelectShapesOnLShiftClick(sf::RenderWindow& window, std::vector<std::shared_ptr<IShape>>& shapes);
    void SingleSelectShapeOnMouseClick(sf::RenderWindow& window, std::vector<std::shared_ptr<IShape>>& shapes);
};