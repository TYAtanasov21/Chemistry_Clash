#pragma once
#include "Macro.h"
#include <iostream>
#include "raylib.h"
#include <string>
#include <vector>
#include <map>
#include <functional>

class CheckButton {
public:
	CheckButton(Rectangle body, std::string text, int textSize, Color mainBodyColor, Color checkBoxBodyColor, Color textColor, std::function<void()> lambda, bool execLambdaIfClicked = 0);

	void Draw();

	void DrawBorder();

	bool IsClicked();

	void Update();
private:
	bool execLambdaIfClicked;
	bool isChecked;
	std::function<void()> lambda;
	Rectangle mainBody;
	Rectangle checkBoxBody;
	std::string text;
	int textSize;
	Color mainBodyColor, textColor, checkBoxBodyColor;
};
