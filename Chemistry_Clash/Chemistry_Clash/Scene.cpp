#include "Scene.h"

//
//void Scene::AddRec(Rectangle rec) {
//	rectangleV.push_back(rec);
//}
//void Scene::AddRec(int x, int y, int width, int height) {
//	Rectangle rec = { x, y, width, height };
//	rectangleV.push_back(rec);
//}

void Scene::AddButton(Button button) {
	this->buttonList.push_back(button);
}

void Scene::AddText(Text text) {
	this->textList.push_back(text);
}

void Scene::SetBackgroundColor(Color backgroundColor) {
	this->backgroundColor = backgroundColor;
}

//void InitScene(Scene* scene, Color backgroundColor) {
//	scene->SetBackgroundColor(backgroundColor);
//}

std::vector<Button>& Scene::GetButtonList() {
	return buttonList;
}