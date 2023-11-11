#include "CheckButton.h"

CheckButton::CheckButton(Rectangle mainBody, std::string text, int textSize, Color mainBodyColor, Color checkBoxBodyColor, Color textColor, std::function<void()> lambda)
{
	this->mainBody = mainBody;
	this->text = text;
	this->textSize = textSize;
	this->mainBodyColor = mainBodyColor;
	this->checkBoxBodyColor = checkBoxBodyColor;
	this->textColor = textColor;
	this->lambda = lambda;

	float checkBoxBodyX = mainBody.x + mainBody.width - textSize - 20;
	float checkBoxBodyY = mainBody.y + (mainBody.height - textSize) / 2;
	this->checkBoxBody = { checkBoxBodyX , checkBoxBodyY, (float)textSize, (float)textSize };
}

void CheckButton::Draw() {

	DrawRectangleRec(mainBody, mainBodyColor);
	DrawBorder();

	if(isChecked == false)
		DrawRectangleRec(checkBoxBody, checkBoxBodyColor);
	else 
		DrawRectangleRec(checkBoxBody, GREEN);

	int textX = mainBody.x + (mainBody.width - MeasureText(text.c_str(), textSize)) / 2 - 20;
	int textY = mainBody.y + (mainBody.height - textSize) / 2;
	DrawText(text.c_str(), textX, textY, textSize, textColor);
}

void CheckButton::DrawBorder() {
	int offset = 5;
	int thickness = 5;
	Rectangle border = mainBody;
	border.width += offset;
	border.height += offset;

	DrawRectangleLinesEx(border, thickness, BLACK);
}

void CheckButton::Update() {
	IsClicked();
}

void CheckButton::IsClicked() {
	double time = GetTime();
	if (IsMouseButtonPressed(0) && CheckCollisionPointRec(GetMousePosition(), checkBoxBody)) {
		isChecked = true;
		std::cout << isChecked;
	}
}