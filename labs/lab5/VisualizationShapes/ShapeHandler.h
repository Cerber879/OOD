#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "IShape.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"
#include "CRectangleFileDecorator.h"
#include "CCircleFileDecorator.h"
#include "CTriangleFileDecorator.h"
#include "CTriangleDrawDecorator.h"
#include "CRectangleDrawDecorator.h"
#include "CCircleDrawDecorator.h"
#include "ToolPanel.h"
#include "ToolPanelManager.h"
#include "IToolPanelState.h"
#include "DragAndDropState.h"
#include "Caretaker.h"

class ShapeHandler
{
	public:
		static ShapeHandler& GetInstance()
		{
			static ShapeHandler instance;
			return instance;
		}

		std::vector<std::shared_ptr<IShape>> GetShapes() { return m_shapes; }
		void SetShapes(std::vector<std::shared_ptr<IShape>>& shapes) { m_shapes = shapes; }

		void AddShape(std::shared_ptr<IShape> shape);
		void RemoveShape(std::shared_ptr<IShape> shape);

		void SetState(std::shared_ptr<IToolPanelState> newState) { m_state = newState; }

		void SetFillColor(ManagerToolPanel::TypeColor& typeColor);
		void SetThicknessCount();

		void Undo();

		void HandleCommands();

	private:
		ShapeHandler() : 
			m_shapes(), 
			m_caretaker(Caretaker::GetInstance()),
			m_toolPanel(ToolPanel::GetInstance()), 
			m_toolPanelManager(ToolPanelManager::GetInstance()),
			m_state(std::make_shared<DragAndDropState>()) {}

		ShapeHandler(const ShapeHandler&) = delete;
		ShapeHandler& operator=(const ShapeHandler&) = delete;

		void GroupSelectedShapesOnCtrlG();
		void UngroupSelectedShapesOnCtrlU();

		void WindowPollEvent(sf::RenderWindow& window);
		void DrawShapes(sf::RenderWindow& window);
		
		void RenderLoop();
		void ReadShapesFromFile(const std::string& filename);
		void WriteResultsToFile(const std::string& filename);

		
		std::vector<std::shared_ptr<IShape>> m_shapes;
		Caretaker& m_caretaker;

		ToolPanel& m_toolPanel;
		ToolPanelManager& m_toolPanelManager;

		std::shared_ptr<IToolPanelState> m_state;
};
