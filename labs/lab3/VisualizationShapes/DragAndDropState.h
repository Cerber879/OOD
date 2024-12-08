#pragma once

#include "IShape.h"
#include "IToolPanelState.h"

class DragAndDropState : public IToolPanelState
{
    public:
        DragAndDropState() : m_lastPosition({ 0, 0 }) {}

        void HandleEvent(sf::Event& event, sf::RenderWindow& window, std::vector<std::shared_ptr<IShape>>& shapes) override;

    private:
        void MultiSelectShapesOnLShiftClick(sf::RenderWindow& window, std::vector<std::shared_ptr<IShape>>& shapes);
        void SingleSelectShapeOnMouseClick(sf::RenderWindow& window, std::vector<std::shared_ptr<IShape>>& shapes);
        void ReleaseShapesOnMouseUp(std::vector<std::shared_ptr<IShape>>& shapes);
        void DragSelectedShapesOnMouseMove(sf::RenderWindow& window, std::vector<std::shared_ptr<IShape>>& shapes);

        sf::Vector2i m_lastPosition;
};