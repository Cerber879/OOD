#include "Button.h"	

Button::Button(const ButtonToolPanel::ButtonShape& buttonShape, const ButtonToolPanel::TextButton& textButton, Command* command)
{
    m_button.setPosition(buttonShape.position);
    m_button.setSize(buttonShape.size);
    m_button.setFillColor(buttonShape.fontColor);
    m_button.setOutlineColor(buttonShape.outlineColor);
    m_button.setOutlineThickness(buttonShape.outlineThickness);

    m_font.loadFromFile(Constants::FileName::PATH_FONT);

    m_text.setFont(m_font);
    m_text.setString(textButton.text);
    m_text.setPosition(textButton.position);
    m_text.setCharacterSize(textButton.characterSize);
    m_text.setFillColor(textButton.fillColor);

	m_isActive = false;
    m_command = command;
}

Button::Button(const ButtonToolPanel::ButtonShape& buttonShape, Command* command)
{
    m_button.setPosition(buttonShape.position);
    m_button.setSize(buttonShape.size);
    m_button.setFillColor(buttonShape.fontColor);
    m_button.setOutlineColor(buttonShape.outlineColor);
    m_button.setOutlineThickness(buttonShape.outlineThickness);

    m_isActive = false;
    m_command =  command;
}

void Button::Draw(sf::RenderWindow& window)
{
    window.draw(m_button);
    window.draw(m_text);
}

bool Button::IsClicked(const sf::Vector2i& mousePosition)
{
    return m_button.getGlobalBounds().contains(mousePosition.x, mousePosition.y);
}

void Button::SetColor(sf::Color& color)
{
    m_button.setFillColor(color);
}

void Button::ExecuteCommand()
{
    if (m_command)
    {
        m_command->Execute();
    }
}