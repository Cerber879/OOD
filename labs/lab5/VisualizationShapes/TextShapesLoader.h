#pragma once

#include "IShapesLoader.h"
#include "IShape.h"

class TextShapesLoader : public IShapesLoader
{
public:
	std::vector<std::shared_ptr<IShape>> LoadShapes(std::istream& stream) override;

private:
	std::shared_ptr<IShape> ProcessingLine(std::istream& stream, std::istream& line);

	CircleData ReadCircleData(std::istream& stream);
	RectangleData ReadRectangleData(std::istream& stream);
	TriangleData ReadTriangleData(std::istream& stream);
	CompositeData ReadCompositeData(std::istream& stream);

	std::vector<std::shared_ptr<IShape>> shapes;
};

