#pragma once
#include "Macro.h"
#include <iostream>
#include "raylib.h"
#include <string>
#include <vector>
#include <map>


class Text {
public:


	Text(std::string text, int textSize, Vector2 textPos, Color textColor = BLACK);

	void Draw();

	int GetTextSize();


private:
	std::string text;
	int textSize;
	Color textColor;
	Vector2 textPos;
};
