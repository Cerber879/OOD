#pragma once

#include "Builder.h"

class CircleBuilder : public Builder
{
public:
	void Build(ShapeData& data) override;
	std::shared_ptr<IShape> GetResult() override;

private:
	sf::CircleShape circleShape;
};

