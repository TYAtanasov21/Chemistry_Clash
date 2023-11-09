#include "Button.h"

Button::Button(Rectangle body, std::string text, int textSize, Color bodyColor, Color textColor, std::function<void()> lambda)
{
	this->body = body;
	this->text = text;
	this->textSize = textSize;
	this->bodyColor = bodyColor;
	this->textColor = textColor;
	this->lambda = lambda;
}

void Button::Draw() {
	DrawRectangleRec(body, bodyColor);
	DrawBorder();
	int textX = body.x + (body.width - MeasureText(text.c_str(), textSize))/2;
	int textY = body.y + (body.height - textSize) / 2;
	DrawText(text.c_str(), textX, textY, textSize, textColor);
}

void Button::DrawBorder() {
	int offset = 5;
	int thickness = 5;
	Rectangle border = body;
	border.width += offset;
	border.height += offset;

	DrawRectangleLinesEx(border, thickness, BLACK);
}

std::function<void()> Button::GetLambda() {
	return this->lambda;
}

bool Button::IsClicked() {
	return (IsMouseButtonPressed(0) && CheckCollisionPointRec(GetMousePosition(), body));
}