#include "ShapeHandler.h"
#include "IShape.h"

int main()
{
    ShapeHandler& handler = ShapeHandler::GetInstance();

    handler.HandleCommands();

    return 0;
};