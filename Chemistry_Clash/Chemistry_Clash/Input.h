#pragma once
#include "Macro.h"
#include <iostream>
#include "raylib.h"
#include <string>
#include <vector>
#include <map>
#include <functional>


class Input {
public:
	Input(Rectangle body, int textSize, Color bodyColor, Color textColor, int minInputSize, int maxInputSize, std::function<void()> lambda);

	void Draw();

	void DrawBorder();

	bool IsSelected();

	void Select();

	void AddChar();

	bool IsHovered();

	void Update();

private:
	int maxInputSize;
	int minInputSize;

	std::string inputString;

	bool isSelected = 0;
	std::function<void()> lambda;
	Rectangle body;
	int textSize;
	Color bodyColor, textColor, bodyColorSecondary;
};

