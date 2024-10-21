#include "ShapeHandler.h"
#include <iostream>

std::vector<std::shared_ptr<CShape>> ShapeHandler::ReadShapesFromFile(const std::string& filename)
{
    std::vector<std::shared_ptr<CShape>> shapes;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string shapeType;
        iss >> shapeType;

        if (shapeType == STR_PREFIX_TRIANGLE)
        {
            CTriangleFileDecorator triangle;
            std::shared_ptr<CShape> shape = triangle.ReadShape(iss);
            shapes.push_back(shape);
        }
        else if (shapeType == STR_PREFIX_RECTANGLE)
        {
            CRectangleFileDecorator rectangle;
            std::shared_ptr<CShape> shape = rectangle.ReadShape(iss);
            shapes.push_back(shape);
        }
        else if (shapeType == STR_PREFIX_CIRCLE)
        {
            CCircleFileDecorator circle;
            std::shared_ptr<CShape> shape = circle.ReadShape(iss);
            shapes.push_back(shape);
        }
    }

    return shapes;
}

void ShapeHandler::WriteResultsToFile(const std::string& filename, const std::vector<std::shared_ptr<CShape>>& shapes)
{
    std::ofstream file(filename);

    for (const std::shared_ptr<CShape>& shape : shapes)
    {
        if (shape->GetType() == RECTANGLE)
        {
            CRectangleFileDecorator rectangle(shape.get());
            file << rectangle.WriteShape(shape);
        }
        else if (shape->GetType() == CIRCLE)
        {
            CCircleFileDecorator circle(shape.get());
            file << circle.WriteShape(shape);
        }
        else if (shape->GetType() == TRIANGLE)
        {
            CTriangleFileDecorator triangle(shape.get());
            file << triangle.WriteShape(shape);
        }
    }
}

void ShapeHandler::DrawShapes(std::vector<std::shared_ptr<CShape>>& shapes)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Geometric Shapes");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();

        for (const std::shared_ptr<CShape>& shape : shapes)
        {
            if (shape->GetType() == RECTANGLE)
            {
                CRectangleDrawDecorator rectangle(shape.get());
                rectangle.Draw(window);
            }
            else if (shape->GetType() == CIRCLE)
            {
                CCircleDrawDecorator circle(shape.get());
                circle.Draw(window);
            }
            else if (shape->GetType() == TRIANGLE)
            {
                CTriangleDrawDecorator triangle(shape.get());
                triangle.Draw(window);
            }
        }

        window.display();
    }
}

void ShapeHandler::HandleCommands(std::vector<std::shared_ptr<CShape>>& shapes)
{
    shapes = ReadShapesFromFile(INPUT);
    WriteResultsToFile(OUTPUT, shapes);
    DrawShapes(shapes);
}
