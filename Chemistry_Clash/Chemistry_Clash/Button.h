#pragma once

#include <iostream>
#include "raylib.h"
#include <string>
#include <vector>
#include <map>


class Button {
public:
	Button(Rectangle body, std::string text, int textSize, Color bodyColor, Color textColor);

	void Draw();

	void DrawBorder();

	bool IsClicked();

private:
	Rectangle body;
	std::string text;
	int textSize;
	Color bodyColor, textColor;

};
