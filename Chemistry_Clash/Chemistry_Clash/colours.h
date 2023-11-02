#pragma once
#include <iostream>
#include "raylib.h"
#include <map>
#include <string>
typedef Color Colour;
class colours {
private:
	std::map <std::string, Colour> colour;
public:
	Colour getColour(std::string key);
	colours();
};