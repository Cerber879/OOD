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
		void HandleCommands(std::vector<std::shared_ptr<CShape>>& shapes);

	private:
		void DrawShapes(std::vector<std::shared_ptr<CShape>>& shapes);
		std::vector<std::shared_ptr<CShape>> ReadShapesFromFile(const std::string& filename);
		void WriteResultsToFile(const std::string& filename, const std::vector<std::shared_ptr<CShape>>& shapes);
};
