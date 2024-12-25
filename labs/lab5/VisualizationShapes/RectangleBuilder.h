#pragma once

#include "Builder.h"

class RectangleBuilder : public Builder
{
public:
	void Build(ShapeData& data) override;
	std::shared_ptr<IShape> GetResult() override;

private:
	sf::RectangleShape rectangleShape;
};

