#include "Scene.h"

Scene::Scene(Color backgroundColor) {
	this->backgroundColor = backgroundColor;
}

void Scene::LoadScene() {
	ClearBackground(backgroundColor);
	for (auto itr = buttonList.begin(); itr != buttonList.end(); itr++) {
		itr->Draw();
	}
}
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
