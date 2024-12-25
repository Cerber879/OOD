#include "LoaderShapesBINCommand.h"
#include "BinaryShapesLoader.h"
#include "ShapeHandler.h"

void LoaderShapesBINCommand::Execute()
{
    Caretaker::GetInstance().Save(Memento(Momento::OperationType::INSERT_INTO_FILE, ShapeHandler::GetInstance().GetShapes()));

    std::ifstream stream(Constants::FileName::SHAPES_BIN);

    BinaryShapesLoader loader;
    std::vector<std::shared_ptr<IShape>> shapes = loader.LoadShapes(stream);
    ShapeHandler::GetInstance().SetShapes(shapes);


    stream.close();
}
