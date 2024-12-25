#pragma once

#include "Builder.h"

class CompositeBuilder : public Builder
{
public:
	void Build(ShapeData& data) override;
	std::shared_ptr<IShape> GetResult() override;

private:
	sf::FloatRect m_boundingBox;
	std::vector<std::shared_ptr<IShape>> m_children;
};

