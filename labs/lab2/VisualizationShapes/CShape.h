#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "StringConstants.h"

class CShape 
{
	public:	
		virtual std::string GetType() const;
        virtual bool Contains(sf::Vector2i position) const;

        virtual bool SetDragging(const bool isDragging);
        virtual const bool IsDragging() const;

        virtual bool SetSelected(bool isSelected);
        virtual const bool IsSelected() const;

        virtual const sf::FloatRect GetBoundingBox() const;

        virtual void Draw(sf::RenderWindow& window) const;
        virtual bool Move(const sf::Vector2i& position);
        virtual void Add(std::shared_ptr<CShape> component);
        virtual void Remove(std::shared_ptr<CShape> component);
        virtual std::vector<std::shared_ptr<CShape>> GetChildren() const;

        virtual ~CShape() = default;
};