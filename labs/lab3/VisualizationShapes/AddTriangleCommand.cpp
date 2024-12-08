#include "AddTriangleCommand.h"
#include "ShapeHandler.h"

void AddTriangleCommand::Execute()
{
	std::shared_ptr<CTriangle> shape = std::make_shared<CTriangle>
	(
		Constants::StartPositionTriangleShape::firstPoint,
		Constants::StartPositionTriangleShape::secondPoint,
		Constants::StartPositionTriangleShape::thirdPoint,
		ToolPanelManager::GetInstance().GetFillColor(),
		ToolPanelManager::GetInstance().GetOutlineColor(),
		ToolPanelManager::GetInstance().GetOutlineThickness()
	);

	ShapeHandler::GetInstance().AddShape(shape);
}
