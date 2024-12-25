#pragma once
#include "IShapeDecorator.h"

class IFileDecorator : public IShapeDecorator
{
	public:
		IFileDecorator(IShape* shape) : IShapeDecorator(shape) {}

		virtual std::shared_ptr<IShape> ReadShape(std::istream& in) = 0;
		virtual std::string WriteShape(const std::shared_ptr<IShape>& shape) const = 0;
};
