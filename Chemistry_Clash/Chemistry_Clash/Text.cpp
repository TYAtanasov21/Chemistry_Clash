#include "Text.h"

Text::Text(std::string text, int textSize, Vector2 textPos, Color textColor) {
	this->text = text;
	this->textSize = textSize;
	this->textPos = textPos;
	this->textColor = textColor;
}

void Text::Draw() {
	DrawText(text.c_str(), textPos.x, textPos.y, textSize, textColor);
}

void Text::Update() {

}

int Text::GetTextSize() {
	return MeasureText(text.c_str(), textSize);
}

void Text::SetText(std::string newText) {
	this->text = newText;
}