#include "SaverShapesTXTCommand.h"
#include "ShapeHandler.h"
#include "TextShapesSaver.h"

void SaverShapesTXTCommand::Execute()
{
    std::vector<std::shared_ptr<IShape>> shapes = ShapeHandler::GetInstance().GetShapes();
    std::ofstream stream(Constants::FileName::SHAPES_TXT);

    TextShapesSaver saver;
    saver.SaveShapes(shapes, stream);
    stream.close();
}
