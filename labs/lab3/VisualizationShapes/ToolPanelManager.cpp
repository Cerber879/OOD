#include "ToolPanelManager.h"

ToolPanelManager::ToolPanelManager() 
{
    m_fillColor = sf::Color::White; 
    m_outlineColor = sf::Color::Black;
    m_outlineThickness = 1;
    m_mode = ManagerToolPanel::TypeMode::DRAG_AND_DROP;
    m_colorType = ManagerToolPanel::TypeColor::FILL;
}

void ToolPanelManager::SetFillColor(const sf::Color& color) 
{
    m_fillColor = color;
}

sf::Color ToolPanelManager::GetFillColor() const
{
    return m_fillColor;
}

void ToolPanelManager::SetOutlineColor(const sf::Color& color) 
{
    m_outlineColor = color;
}

sf::Color ToolPanelManager::GetOutlineColor() const 
{
    return m_outlineColor;
}

void ToolPanelManager::SetOutlineThickness(int thickness)
{
    m_outlineThickness = thickness;
}

int ToolPanelManager::GetOutlineThickness() const
{
    return m_outlineThickness;
}

void ToolPanelManager::SetColorType(const ManagerToolPanel::TypeColor& colorType)
{
    m_colorType = colorType;
}

ManagerToolPanel::TypeColor ToolPanelManager::GetColorType() const
{
    return m_colorType;
}

void ToolPanelManager::SetMode(const ManagerToolPanel::TypeMode& mode)
{
    m_mode = mode;
}

ManagerToolPanel::TypeMode ToolPanelManager::GetMode() const
{
    return m_mode;
}
