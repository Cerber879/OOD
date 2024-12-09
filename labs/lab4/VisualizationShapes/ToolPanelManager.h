#pragma once

#include "IShape.h"
#include <stack>

class ToolPanelManager 
{
    public:
        static ToolPanelManager& GetInstance()
        {
            static ToolPanelManager instance;
            return instance;
        }

        ToolPanelManager(const ToolPanelManager&) = delete;
        ToolPanelManager& operator=(const ToolPanelManager&) = delete;

        void SetFillColor(const sf::Color& color);
        sf::Color GetFillColor() const;

        void SetOutlineColor(const sf::Color& color);
        sf::Color GetOutlineColor() const;

        void SetOutlineThickness(int thickness);
        int GetOutlineThickness() const;

        void SetColorType(const ManagerToolPanel::TypeColor& colorType);
        ManagerToolPanel::TypeColor GetColorType() const;

        void SetMode(const ManagerToolPanel::TypeMode& mode);
        ManagerToolPanel::TypeMode GetMode() const;

        void SetLastPosition(const sf::Vector2i& mode);
        sf::Vector2i GetLastPosition();

    private:
        ToolPanelManager();

        sf::Color m_fillColor;
        sf::Color m_outlineColor;
        int m_outlineThickness;
        ManagerToolPanel::TypeColor m_colorType;
        ManagerToolPanel::TypeMode m_mode;
        std::stack<sf::Vector2i> m_lastPosition;
};