#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "CShape.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "CRectangleFileDecorator.h"
#include "CCircleFileDecorator.h"
#include "CTriangleFileDecorator.h"
#include "CTriangleDrawDecorator.h"
#include "CRectangleDrawDecorator.h"
#include "CCircleDrawDecorator.h"

class ShapeHandler
{
	public:
		ShapeHandler() : m_shapes(), m_lastPosition({ 0, 0 }) {}

		void HandleCommands();

	private:
		void MouseLeftButtonPressedWithLShift(sf::RenderWindow& window);
		void MouseLeftButtonPressed(sf::RenderWindow& window);
		void MouseLeftButtonReleased();
		void MouseLeftButtonMoved(sf::RenderWindow& window);
		void KeyGWithLControlPressed();
		void KeyUWithLControlPressed();

		void WindowPollEvent(sf::RenderWindow& window);
		void DrawShapes(sf::RenderWindow& window);
		
		void RenderLoop();
		void ReadShapesFromFile(const std::string& filename);
		void WriteResultsToFile(const std::string& filename);

		
		std::vector<std::shared_ptr<CShape>> m_shapes;
		sf::Vector2i m_lastPosition;
};
