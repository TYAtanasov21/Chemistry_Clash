#pragma once

#include <iostream>
#include "raylib.h"
#include <string>

typedef Color Colour;

struct Button {
	Colour btnClr, borderClr, txtClr;
	int btnWidth, btnHeight, textSize, borderSize;
	std::string text;
	Vector2 btnPos;

};


void makeButton(Vector2 btnPos, std::string text, int textSize,int btnWidth, int btnHeight, int borderSize, Colour btnClr, Colour borderClr, Colour txtClr);

void drawTextC(std::string text, int posX, int posY, int textSize, Colour clr);