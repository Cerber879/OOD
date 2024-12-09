#pragma once
#include "IFileDecorator.h"

class CCircleFileDecorator : public IFileDecorator
{
public:
	CCircleFileDecorator(IShape* shape) : IFileDecorator(shape) {}
	CCircleFileDecorator() : IFileDecorator(nullptr) {}

	std::shared_ptr<IShape> ReadShape(std::istream& in) override;
	std::string WriteShape(const std::shared_ptr<IShape>& shape) const override;
};

