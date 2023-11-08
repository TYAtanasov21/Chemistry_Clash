#pragma once
#include "Macro.h"
#include <iostream>
#include "Button.h"

class Scene {
public:
	//Scene();
	virtual void LoadScene() = 0;
	void InitButtonList(std::vector<Button> buttonList);
	void SetBackgroundColor(Color backgroundColor);
	std::vector<Button>& GetButtonList();
protected:
	Color backgroundColor;
	std::vector<Button> buttonList;
};

void InitScene(Scene* scene, std::vector<Button> buttonList, Color backgroundColor);
