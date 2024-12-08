#include <unordered_map>
#include <memory>
#include <string>
#include "IShapeWriterState.h"
#include "RectangleWriterState.h"
#include "CircleWriterState.h"
#include "TriangleWriterState.h"
#include "Constants.h"

class ShapeWriterStateFactory 
{
    public:
        ShapeWriterStateFactory();

        IShapeWriterState* GetState(const std::string& shapeType);

    private:
        std::unordered_map<std::string, std::unique_ptr<IShapeWriterState>> states;
};