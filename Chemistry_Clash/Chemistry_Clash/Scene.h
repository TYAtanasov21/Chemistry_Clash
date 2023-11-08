#pragma once
#include <iostream>
#include "Macro.h"
#include "Button.h"
#include "Text.h"

class Scene {
public:
	//Scene();
	virtual void LoadScene() = 0;
	void AddButton(Button button);
	void AddText(Text text);
	void SetBackgroundColor(Color backgroundColor);
	std::vector<Button>& GetButtonList();
protected:
	Color backgroundColor;
	std::vector<Button> buttonList;
	std::vector<Text> textList;
};

//void InitScene(Scene* scene, std::vector<Button> buttonList, Color backgroundColor);
