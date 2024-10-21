#include "ShapeHandler.h"
#include "CShape.h"

int main()
{
	std::vector<std::shared_ptr<CShape>> shapes;
	std::shared_ptr<ShapeHandler> handler;

	handler->HandleCommands(shapes);

	return 0;
}