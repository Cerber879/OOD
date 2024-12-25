#include "SaverShapesBINCommand.h"

#include "ShapeHandler.h"
#include "BinaryShapesSaver.h"

void SaverShapesBINCommand::Execute()
{
    std::vector<std::shared_ptr<IShape>> shapes = ShapeHandler::GetInstance().GetShapes();
    std::ofstream stream(Constants::FileName::SHAPES_BIN);

    BinaryShapesSaver saver;
    saver.SaveShapes(shapes, stream);

    stream.close();
}
