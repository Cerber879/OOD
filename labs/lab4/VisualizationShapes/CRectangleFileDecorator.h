#pragma once
#include "IFileDecorator.h"

class CRectangleFileDecorator : public IFileDecorator
{
	public:
		CRectangleFileDecorator(IShape* shape) : IFileDecorator(shape) {}
		CRectangleFileDecorator() : IFileDecorator(nullptr) {}

		std::shared_ptr<IShape> ReadShape(std::istream& in) override;
		std::string WriteShape(const std::shared_ptr<IShape>& shape) const override;
};

