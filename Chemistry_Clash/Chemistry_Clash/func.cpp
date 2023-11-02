#include "func.h"
#include "game.h"


void makeButton(Vector2 btnPos, std::string text, int textSize, int btnWidth, int btnHeight, int borderSize, Colour btnClr, Colour borderClr, Colour txtClr){
	DrawRectangle(btnPos.x - (btnWidth / 2) - borderSize, btnPos.y - (btnHeight / 2) - borderSize, btnWidth + (borderSize*2), btnHeight + (borderSize*2), borderClr);
	DrawRectangle(btnPos.x - (btnWidth / 2), btnPos.y - (btnHeight / 2), btnWidth, btnHeight, btnClr);
	DrawText(text.c_str(), (btnPos.x - btnWidth / 2) + (btnWidth - MeasureText(text.c_str(), textSize)) / 2, btnPos.y - (btnHeight) /2 + (btnHeight - textSize)/2, textSize, txtClr);
}

