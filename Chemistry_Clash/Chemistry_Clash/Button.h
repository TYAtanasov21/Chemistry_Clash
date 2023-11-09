#pragma once
#include "Macro.h"
#include <iostream>
#include "raylib.h"
#include <string>
#include <vector>
#include <map>
#include <functional>


class Button {
public:
	Button(Rectangle body, std::string text, int textSize, Color bodyColor, Color textColor, std::function<void()> lambda);

	void Draw();

	void DrawBorder();

	bool IsClicked();

	void Update();

private:
	std::function<void()> lambda;
	Rectangle body;
	std::string text;
	int textSize;
	Color bodyColor, textColor;
};
