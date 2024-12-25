#pragma once
#include "IShape.h"
#include "Button.h"
#include "Constants.h"

class ToolPanel
{
	public:
		static ToolPanel& GetInstance()
		{
			static ToolPanel instance;
			return instance;
		}

		ToolPanel(const ToolPanel&) = delete;
		ToolPanel& operator=(const ToolPanel&) = delete;

		std::shared_ptr<Button> GetFillColorButton() const;
		std::shared_ptr<Button> GetOutlineColorButton() const;

		void Draw(sf::RenderWindow& window);
		bool HandleEvent(sf::Event& event, sf::RenderWindow& window);

	private:
		ToolPanel();

		std::vector<std::shared_ptr<Button>> m_buttons;
		std::shared_ptr<Button> m_background;

		std::shared_ptr<Button> m_fillColorButton;
		std::shared_ptr<Button> m_outlineColorButton;
};