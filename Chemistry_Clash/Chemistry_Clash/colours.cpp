#include "colours.h"
colours::colours(){
	this->colour["darkBlue"] = { 44, 54, 57 };
}
Colour colours::getColour(std::string key) {
	return this->colour[key];
}