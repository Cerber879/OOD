#include "LoaderShapesTXTCommand.h"
#include "TextShapesLoader.h"
#include "ShapeHandler.h"

void LoaderShapesTXTCommand::Execute()
{
    std::ifstream stream(Constants::FileName::SHAPES_TXT);

    TextShapesLoader loader;
    std::vector<std::shared_ptr<IShape>> shapes = loader.LoadShapes(stream);
    ShapeHandler::GetInstance().SetShapes(shapes);

    stream.close();
}
