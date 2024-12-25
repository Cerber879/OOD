#include "ToolPanel.h"

#include "NullCommand.h"

#include "AddTriangleCommand.h"
#include "AddRectangleCommand.h"
#include "AddCircleCommand.h"
#include "SetColorCommand.h"
#include "SetTypeColorCommand.h"
#include "SetOutlineThicknessCommand.h"
#include "SetModeCommand.h"

#include "SaverShapesTXTCommand.h"
#include "SaverShapesBINCommand.h"
#include "LoaderShapesTXTCommand.h"
#include "LoaderShapesBINCommand.h"

ToolPanel::ToolPanel()
{
    m_background = std::make_shared<Button>(ButtonToolPanel::BACKGROUND, new NullCommand());

    m_buttons.push_back(std::make_shared<Button>(ButtonToolPanel::BUTTON_DRAG_AND_DROP_MODE, ButtonToolPanel::TEXT_BUTTON_DRAG_AND_DROP, new SetModeCommand(ManagerToolPanel::TypeMode::DRAG_AND_DROP)));
    m_buttons.push_back(std::make_shared<Button>(ButtonToolPanel::BUTTON_FILLING_MODE, ButtonToolPanel::TEXT_FILLING, new SetModeCommand(ManagerToolPanel::TypeMode::FILLING)));

    // Инициализация кнопок
    m_buttons.push_back(std::make_shared<Button>(ButtonToolPanel::BUTTON_ADD_RECTANGLE, ButtonToolPanel::TEXT_ADD_RECTANGLE, new AddRectangleCommand()));
    m_buttons.push_back(std::make_shared<Button>(ButtonToolPanel::BUTTON_ADD_TRIANGLE, ButtonToolPanel::TEXT_ADD_TRIANGLE, new AddTriangleCommand()));
    m_buttons.push_back(std::make_shared<Button>(ButtonToolPanel::BUTTON_ADD_CIRCLE, ButtonToolPanel::TEXT_ADD_CIRCLE, new AddCircleCommand()));

    // Инициализация блоков текущего цвета
    m_fillColorButton = std::make_shared<Button>(ButtonToolPanel::COLOR_BLOCK_FILL, ButtonToolPanel::TEXT_COLOR_BLOCK_FILL, new SetTypeColorCommand(ManagerToolPanel::TypeColor::FILL));
    m_outlineColorButton = std::make_shared<Button>(ButtonToolPanel::COLOR_BLOCK_OUTLINE, ButtonToolPanel::TEXT_COLOR_BLOCK_OUTLINE, new SetTypeColorCommand(ManagerToolPanel::TypeColor::OUTLINE));

    // Инициализация цветовых блоков
    m_buttons.push_back(std::make_shared<Button>(ButtonToolPanel::COLOR_BLOCK_BLACK, new SetColorCommand(sf::Color::Black)));
    m_buttons.push_back(std::make_shared<Button>(ButtonToolPanel::COLOR_BLOCK_WHITE, new SetColorCommand(sf::Color::White)));
    m_buttons.push_back(std::make_shared<Button>(ButtonToolPanel::COLOR_BLOCK_RED, new SetColorCommand(sf::Color::Red)));
    m_buttons.push_back(std::make_shared<Button>(ButtonToolPanel::COLOR_BLOCK_GREEN, new SetColorCommand(sf::Color::Green)));
    m_buttons.push_back(std::make_shared<Button>(ButtonToolPanel::COLOR_BLOCK_BLUE, new SetColorCommand(sf::Color::Cyan)));
    m_buttons.push_back(std::make_shared<Button>(ButtonToolPanel::COLOR_BLOCK_YELLOW, new SetColorCommand(sf::Color::Yellow)));
    m_buttons.push_back(std::make_shared<Button>(ButtonToolPanel::COLOR_BLOCK_MAGENTA, new SetColorCommand(sf::Color::Magenta)));
    m_buttons.push_back(std::make_shared<Button>(ButtonToolPanel::COLOR_BLOCK_TRANSPARENT, new SetColorCommand(sf::Color::Transparent)));

    // Инициализация кнопок толщины линий
    m_buttons.push_back(std::make_shared<Button>(ButtonToolPanel::THICKNESS_BUTTON_2, new SetOutlineThicknessCommand(1)));
    m_buttons.push_back(std::make_shared<Button>(ButtonToolPanel::THICKNESS_BUTTON_4, new SetOutlineThicknessCommand(4)));
    m_buttons.push_back(std::make_shared<Button>(ButtonToolPanel::THICKNESS_BUTTON_6, new SetOutlineThicknessCommand(7)));

    m_buttons.push_back(std::make_shared<Button>(ButtonToolPanel::BUTTON_UPLOAD_TXT, ButtonToolPanel::TEXT_UPLOAD_TXT, new SaverShapesTXTCommand()));
    m_buttons.push_back(std::make_shared<Button>(ButtonToolPanel::BUTTON_UPLOAD_BIN, ButtonToolPanel::TEXT_UPLOAD_BIN, new SaverShapesBINCommand()));

    m_buttons.push_back(std::make_shared<Button>(ButtonToolPanel::BUTTON_UNLOAD_TXT, ButtonToolPanel::TEXT_UNLOAD_TXT, new LoaderShapesTXTCommand()));
    m_buttons.push_back(std::make_shared<Button>(ButtonToolPanel::BUTTON_UNLOAD_BIN, ButtonToolPanel::TEXT_UNLOAD_BIN, new LoaderShapesBINCommand()));
}

std::shared_ptr<Button> ToolPanel::GetFillColorButton() const
{
    return m_fillColorButton;
}

std::shared_ptr<Button> ToolPanel::GetOutlineColorButton() const
{
    return m_outlineColorButton;
}

void ToolPanel::Draw(sf::RenderWindow& window)
{
    m_background->Draw(window);
    m_fillColorButton->Draw(window);
    m_outlineColorButton->Draw(window);

	for (std::shared_ptr<Button>& button : m_buttons)
	{
		button->Draw(window);
	}
}

bool ToolPanel::HandleEvent(sf::Event& event, sf::RenderWindow& window)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        for (const auto& button : m_buttons)
        {
            if (button->IsClicked(mousePosition))
            {
                button->ExecuteCommand();
            }
        }

        if (m_fillColorButton->IsClicked(mousePosition))
        {
            m_fillColorButton->ExecuteCommand();
        }
        else if (m_outlineColorButton->IsClicked(mousePosition))
        {
            m_outlineColorButton->ExecuteCommand();
        }

        if (m_background->IsClicked(mousePosition))
        {
            return true;
        }
    }

    return false;
}
