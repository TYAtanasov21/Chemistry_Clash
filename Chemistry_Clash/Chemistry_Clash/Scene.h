#pragma once
#include "Macro.h"
#include <iostream>
#include "Button.h"

class Scene {
public:
	Scene(Color backgroundColor);
	void LoadScene();
	void AddRec(Rectangle);
	void AddRec(int x, int y, int width, int height);

private:
	Color backgroundColor;
	std::vector<Rectangle> rectangleV;
};

