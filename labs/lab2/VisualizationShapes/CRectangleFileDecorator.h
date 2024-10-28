#pragma once
#include "CFileDecorator.h"

class CRectangleFileDecorator : public CFileDecorator
{
	public:
		CRectangleFileDecorator(CShape* shape) : CFileDecorator(shape) {}
		CRectangleFileDecorator() : CFileDecorator(nullptr) {}

		std::shared_ptr<CShape> ReadShape(std::istream& in) override;
		std::string WriteShape(const std::shared_ptr<CShape>& shape) const override;
};

