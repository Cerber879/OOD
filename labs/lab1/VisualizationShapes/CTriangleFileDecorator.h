#pragma once
#include "CFileDecorator.h"

class CTriangleFileDecorator : public CFileDecorator
{
public:
	CTriangleFileDecorator(CShape* shape) : CFileDecorator(shape) {}
	CTriangleFileDecorator() : CFileDecorator(nullptr) {}

	std::string GetType() const override;

	std::shared_ptr<CShape> ReadShape(std::istream& in) override;
	std::string WriteShape(const std::shared_ptr<CShape>& shape) const override;
};

