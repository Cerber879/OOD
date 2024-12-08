#pragma once
#include <string>
#include <SFML/Graphics.hpp>

namespace Window
{
    const std::string NAME = "Geometric shapes";
    const int WIDTH = 1280;
    const int HEIGHT = 720;
}

namespace Constants
{
    namespace StartPositionRectangleShape
    {
        const sf::Vector2f firstPoint = { 0, 60 };
        const sf::Vector2f secondPoint = { 100, 160 };
    }

    namespace StartPositionTriangleShape
    {
        const sf::Vector2f firstPoint = { 50, 60 };
        const sf::Vector2f secondPoint = { 100, 160 };
        const sf::Vector2f thirdPoint = { 0, 160 };
    }

    namespace StartPositionCircleShape
    {
        const sf::Vector2f centerPoint = { 50, 110 };
        const float radius = 50.0;
    }

	namespace Number
	{
		const float TWO = 2.0;
		const float THREE = 3.0;
	};

	namespace MathConstant
	{
		const float PI = 3.14159;
	};

	namespace Char
	{
		const char SEMICOLON = '/;';
	};

    namespace FileName
	{
		const std::string PATH_FONT = "C:/Users/User/source/repos/OOD/labs/lab3/fonts/Roboto-Light.ttf";

        const std::string INPUT_ROBOT = "ROBOT.TXT";
        const std::string VOID_FILE = "VOID.TXT";
		const std::string INPUT = "INPUT.TXT";
		const std::string OUTPUT = "OUTPUT.TXT";
	};

	namespace TypeShape
	{
		const std::string TRIANGLE = "TRIANGLE";
		const std::string RECTANGLE = "RECTANGLE";
		const std::string CIRCLE = "CIRCLE";
		const std::string COMPOSITE = "COMPOSITE";
	};

	namespace PrefixShape
	{
		const std::string STR_PREFIX_TRIANGLE = "TRIANGLE:";
		const std::string STR_PREFIX_RECTANGLE = "RECTANGLE:";
		const std::string STR_PREFIX_CIRCLE = "CIRCLE:";
	};

	namespace PrefixMath
	{
		const std::string STR_PREFIX_PERIMETER = " P=";
		const std::string STR_PREFIX_AREA = " S=";
	};

	namespace ErrorText
	{
		const std::string INVALID_BODY_TYPE = "Invalid body type: ";
		const std::string POINT_OUT_OF_RANGE = "Point out of range";
	};
}

namespace ManagerToolPanel
{
    enum TypeColor
    {
        FILL,
        OUTLINE
    };

    enum TypeMode
    {
        DRAG_AND_DROP,
        FILLING
    };
}


namespace ButtonToolPanel
{
    struct ButtonShape
    {
        ButtonShape(sf::Vector2f pos, sf::Vector2f sz, sf::Color fontCol, sf::Color outlineCol, int outlineThick)
            : position(pos), size(sz), fontColor(fontCol), outlineColor(outlineCol), outlineThickness(outlineThick) {}

        ButtonShape()
            : position(0, 0), size(0, 0), fontColor(sf::Color::Blue), outlineColor(sf::Color::Blue), outlineThickness(0) {}

        const sf::Vector2f position;
        const sf::Vector2f size;
        const sf::Color fontColor;
        const sf::Color outlineColor;
        const int outlineThickness;
    };

    struct TextButton
    {
        TextButton(std::string txt, sf::Vector2f pos, int charSize, sf::Color fillCol)
            : text(txt), position(pos), characterSize(charSize), fillColor(fillCol) {}

        TextButton()
            : text(""), position(0, 0), characterSize(0), fillColor(sf::Color::Blue) {}

        const std::string text;
        const sf::Vector2f position;
        const int characterSize;
        const sf::Color fillColor;
    };

    // Константы для кнопок
    const ButtonShape BUTTON_ADD_RECTANGLE = ButtonShape(sf::Vector2f(10, 10), sf::Vector2f(100, 40), sf::Color::White, sf::Color::Black, 2);
    const TextButton TEXT_ADD_RECTANGLE = TextButton("Rectangle", sf::Vector2f(25, 20), 16, sf::Color::Black);

    const ButtonShape BUTTON_ADD_TRIANGLE = ButtonShape(sf::Vector2f(120, 10), sf::Vector2f(100, 40), sf::Color::White, sf::Color::Black, 2);
    const TextButton TEXT_ADD_TRIANGLE = TextButton("Triangle", sf::Vector2f(143, 20), 16, sf::Color::Black);

    const ButtonShape BUTTON_ADD_CIRCLE = ButtonShape(sf::Vector2f(230, 10), sf::Vector2f(100, 40), sf::Color::White, sf::Color::Black, 2);
    const TextButton TEXT_ADD_CIRCLE = TextButton("Circle", sf::Vector2f(260, 20), 16, sf::Color::Black);

    // Константы для кнопок толщины линий
    const ButtonShape THICKNESS_BUTTON_2 = ButtonShape(sf::Vector2f(350, 9), sf::Vector2f(60, 6), sf::Color::White, sf::Color::Black, 1);
    const ButtonShape THICKNESS_BUTTON_4 = ButtonShape(sf::Vector2f(350, 21), sf::Vector2f(60, 10), sf::Color::White, sf::Color::Black, 1);
    const ButtonShape THICKNESS_BUTTON_6 = ButtonShape(sf::Vector2f(350, 37), sf::Vector2f(60, 14), sf::Color::White, sf::Color::Black, 1);

    // Инициализация блоков текущего цвета
    const ButtonShape COLOR_BLOCK_FILL = ButtonShape(sf::Vector2f(430, 10), sf::Vector2f(27, 27), sf::Color::White, sf::Color::Black, 2);
    const TextButton TEXT_COLOR_BLOCK_FILL = TextButton("Color 1", sf::Vector2f(430, 40), 10, sf::Color::Black);

    const ButtonShape COLOR_BLOCK_OUTLINE = ButtonShape(sf::Vector2f(470, 10), sf::Vector2f(27, 27), sf::Color::Black, sf::Color::Black, 2);
    const TextButton TEXT_COLOR_BLOCK_OUTLINE = TextButton("Color 2", sf::Vector2f(470, 40), 10, sf::Color::Black);

    // Константы для цветовых блоков
    const ButtonShape COLOR_BLOCK_BLACK = ButtonShape(sf::Vector2f(520, 8), sf::Vector2f(18, 18), sf::Color::Black, sf::Color(128, 128, 128), 1);
    const ButtonShape COLOR_BLOCK_WHITE = ButtonShape(sf::Vector2f(520, 32), sf::Vector2f(18, 18), sf::Color::White, sf::Color(128, 128, 128), 1);
    const ButtonShape COLOR_BLOCK_RED = ButtonShape(sf::Vector2f(545, 8), sf::Vector2f(18, 18), sf::Color::Red, sf::Color(128, 128, 128), 1);
    const ButtonShape COLOR_BLOCK_GREEN = ButtonShape(sf::Vector2f(545, 32), sf::Vector2f(18, 18), sf::Color::Green, sf::Color(128, 128, 128), 1);
    const ButtonShape COLOR_BLOCK_YELLOW = ButtonShape(sf::Vector2f(570, 8), sf::Vector2f(18, 18), sf::Color::Yellow, sf::Color(128, 128, 128), 1);
    const ButtonShape COLOR_BLOCK_BLUE = ButtonShape(sf::Vector2f(570, 32), sf::Vector2f(18, 18), sf::Color::Cyan, sf::Color(128, 128, 128), 1);
    const ButtonShape COLOR_BLOCK_MAGENTA = ButtonShape(sf::Vector2f(595, 8), sf::Vector2f(18, 18), sf::Color::Magenta, sf::Color(128, 128, 128), 1);
    const ButtonShape COLOR_BLOCK_TRANSPARENT = ButtonShape(sf::Vector2f(595, 32), sf::Vector2f(18, 18), sf::Color::Transparent, sf::Color(128, 128, 128), 1);


    const ButtonShape BUTTON_DRAG_AND_DROP_MODE = ButtonShape(sf::Vector2f(630, 10), sf::Vector2f(40, 40), sf::Color::White, sf::Color::Black, 2);
    const TextButton TEXT_BUTTON_DRAG_AND_DROP = TextButton("DaD", sf::Vector2f(637, 20), 14, sf::Color::Black);

    const ButtonShape BUTTON_FILLING_MODE = ButtonShape(sf::Vector2f(680, 10), sf::Vector2f(40, 40), sf::Color::White, sf::Color::Black, 2);
    const TextButton TEXT_FILLING = TextButton("Fill", sf::Vector2f(692, 20), 14, sf::Color::Black);

    // Задний фон панели инструментов
    const ButtonShape BACKGROUND = ButtonShape(sf::Vector2f(0, 0), sf::Vector2f(730, 60), sf::Color(30, 144, 255), sf::Color(47, 79, 79), 1);
}

namespace BTP = ButtonToolPanel;
