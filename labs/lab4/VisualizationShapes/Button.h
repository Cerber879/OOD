#pragma once
#include "IShape.h"
#include "Constants.h"	
#include "Command.h"

class Button
{
	public:
		Button(const ButtonToolPanel::ButtonShape& buttonShape, const ButtonToolPanel::TextButton& textButton, Command* command);
		Button(const ButtonToolPanel::ButtonShape& buttonShape, Command* command);
		
		void Draw(sf::RenderWindow& window);
		bool IsClicked(const sf::Vector2i& mousePosition);
		void SetColor(sf::Color& color);
		void ExecuteCommand();

	private:
		sf::RectangleShape m_button;
		sf::Text m_text;
		sf::Font m_font;
		bool m_isActive;
		Command* m_command;
};

