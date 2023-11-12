#include "Input.h"

Input::Input(Rectangle body, int textSize, Color bodyColor, Color textColor, int minInputSize, int maxInputSize,std::function<void()> lambda)
{
	this->body = body;
	this->textSize = textSize;
	this->bodyColor = bodyColor;
	this->textColor = textColor;
	this->lambda = lambda;
	this->bodyColorSecondary = { bodyColor.r /= 3, bodyColor.g /= 3, bodyColor.b /= 3, 80 };
	this->maxInputSize = maxInputSize;
	this->minInputSize = minInputSize;
}
bool Input::IsHovered()
{
	return (CheckCollisionPointRec(GetMousePosition(), body));
}

void Input::Draw() {
	if (IsHovered()||isSelected)
	{
		DrawRectangleRec(body, bodyColorSecondary);
	}
	else {
		DrawRectangleRec(body, bodyColor);
	}
	int textX = body.x + (body.width - MeasureText(inputString.c_str(), textSize)) / 2;
	int textY = body.y + (body.height - textSize) / 2;
	if(inputString.size()!=0)
		DrawText(inputString.c_str(), textX, textY, textSize, textColor);
	DrawBorder();
}

void Input::DrawBorder() {
	int offset = 4;
	int thickness = 4;
	Rectangle border = body;
	border.width += offset;
	border.height += offset;
	if(!isSelected)
		DrawRectangleLinesEx(border, thickness, NAVYBLUE);
	else
		DrawRectangleLinesEx(border, thickness, BLACK);
}

void Input::Update() {
	Select();
	AddChar();
}

void Input::Select() {
	if (IsMouseButtonPressed(0)) {
		this->isSelected = (CheckCollisionPointRec(GetMousePosition(), body));
	}
}

bool Input::IsSelected() {
	return isSelected;
}

void Input::AddChar() {
	if (isSelected) {
		int key = GetKeyPressed();

		if (key != KEY_BACKSPACE && key >= 33 && key <= 122) {
			if (inputString.size() < maxInputSize) {
				inputString.push_back((char)key);
			}
		}
		if (key == KEY_BACKSPACE) {
			if (inputString.size() > 0) {
				inputString.pop_back();
			}
		}
	}
}