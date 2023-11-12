#include "Text.h"

Text::Text(std::string text, int textSize, Vector2 textPos, Color textColor, std::function<void()> updateLambda) {
	this->text = text;
	this->textSize = textSize;
	this->textPos = textPos;
	this->textColor = textColor;
	this->updateLambda = updateLambda;
}

void Text::Draw() {
	DrawText(text.c_str(), textPos.x, textPos.y, textSize, textColor);
}

void Text::Update() {
	updateLambda();
}

int Text::GetTextSize() {
	return MeasureText(text.c_str(), textSize);
}