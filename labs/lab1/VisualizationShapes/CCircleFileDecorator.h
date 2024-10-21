#pragma once
#include "CFileDecorator.h"

class CCircleFileDecorator : public CFileDecorator
{
public:
	CCircleFileDecorator(CShape* shape) : CFileDecorator(shape) {}
	CCircleFileDecorator() : CFileDecorator(nullptr) {}

	std::string GetType() const override;

	std::shared_ptr<CShape> ReadShape(std::istream& in) override;
	std::string WriteShape(const std::shared_ptr<CShape>& shape) const override;
};

