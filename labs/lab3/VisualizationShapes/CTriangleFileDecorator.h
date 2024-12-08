#pragma once
#include "IFileDecorator.h"

class CTriangleFileDecorator : public IFileDecorator
{
public:
	CTriangleFileDecorator(IShape* shape) : IFileDecorator(shape) {}
	CTriangleFileDecorator() : IFileDecorator(nullptr) {}

	std::shared_ptr<IShape> ReadShape(std::istream& in) override;
	std::string WriteShape(const std::shared_ptr<IShape>& shape) const override;
};

