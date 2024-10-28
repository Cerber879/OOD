#pragma once
#include "CShapeDecorator.h"

class CFileDecorator : public CShapeDecorator
{
	public:
		CFileDecorator(CShape* shape) : CShapeDecorator(shape) {}

		virtual std::shared_ptr<CShape> ReadShape(std::istream& in) = 0;
		virtual std::string WriteShape(const std::shared_ptr<CShape>& shape) const = 0;
};
