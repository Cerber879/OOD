#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "IVisitor.h"

class IShape 
{
	public:	
		virtual std::string GetType() const;
        virtual void Accept(IVisitor& visitor);

        virtual bool Contains(sf::Vector2i position) const;
        virtual bool ContainsFill(sf::Vector2i position) const;

        virtual bool SetDragging(const bool isDragging);
        virtual const bool IsDragging() const;

        virtual bool SetSelected(bool isSelected);
        virtual const bool IsSelected() const;

        virtual const sf::FloatRect GetBoundingBox() const;

        virtual void SetFillColor(const sf::Color& color);
        virtual sf::Color GetFillColor();

        virtual void SetOutlineColor(const sf::Color& color);
        virtual sf::Color GetOutlineColor();

        virtual void SetThicknessCount(const int& count);
        virtual int GetThicknessCount();

        virtual void Draw(sf::RenderWindow& window) const;
        virtual bool Move(const sf::Vector2i& position);
        virtual void Add(std::shared_ptr<IShape> component);
        virtual void Remove(std::shared_ptr<IShape> component);
        virtual std::vector<std::shared_ptr<IShape>> GetChildren() const;

        virtual void SerializeTXT(std::ostream& stream) const;
        virtual void SerializeBIN(std::ostream& stream) const;
        virtual void DeserializeTXT(std::istream& stream);
        virtual void DeserializeBIN(std::istream& stream);

        virtual ~IShape() = default;
};