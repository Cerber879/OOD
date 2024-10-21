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
		virtual std::string GetType() const = 0;
};