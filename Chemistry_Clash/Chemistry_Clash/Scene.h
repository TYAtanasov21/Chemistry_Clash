#pragma once
#include "Macro.h"
#include <iostream>
#include "Button.h"

class Scene {
public:
	Scene(Color backgroundColor);
	void LoadScene();
	void InitButtonList(std::vector<Button> buttonList);

private:
	Color backgroundColor;
	std::vector<Button> buttonList;
};

