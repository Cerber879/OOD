#pragma once

class IShape;
class CRectangle;
class CTriangle;
class CCircle;

class IVisitor
{
public:
    virtual void Visit(CRectangle& rectangle) = 0;
    virtual void Visit(CTriangle& triangle) = 0;
    virtual void Visit(CCircle& circle) = 0;
    virtual ~IVisitor() = default;
};
