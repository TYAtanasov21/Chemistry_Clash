#include "Scene.h"

//
//void Scene::AddRec(Rectangle rec) {
//	rectangleV.push_back(rec);
//}
//void Scene::AddRec(int x, int y, int width, int height) {
//	Rectangle rec = { x, y, width, height };
//	rectangleV.push_back(rec);
//}

void Scene::InitButtonList(std::vector<Button> buttonList) {
	this->buttonList = buttonList;
}

void Scene::SetBackgroundColor(Color backgroundColor) {
	this->backgroundColor = backgroundColor;
}

void InitScene(Scene* scene, std::vector<Button> buttonList, Color backgroundColor){
	scene->SetBackgroundColor(backgroundColor);
	scene->InitButtonList(buttonList);
}
std::vector<Button>& Scene::GetButtonList() {
	return buttonList;
}