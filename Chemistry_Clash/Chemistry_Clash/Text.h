#pragma once
#include "Macro.h"
#include <iostream>
#include "raylib.h"
#include <string>
#include <vector>
#include <map>
#include <functional>

class Text {
public:


	Text(std::string text, int textSize, Vector2 textPos, Color textColor, std::function<void()> updateLambda = 0);

	void Draw();

	void Update();

	int GetTextSize();




private:

	std::function<void()> updateLambda;
	std::string text;
	int textSize;
	Color textColor;
	Vector2 textPos;
};
