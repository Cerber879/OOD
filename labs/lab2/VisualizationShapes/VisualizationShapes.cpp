#include "ShapeHandler.h"
#include "CShape.h"

int main()
{
    std::shared_ptr<ShapeHandler> handler = std::make_shared<ShapeHandler>();

    handler->HandleCommands();

	return 0;
}