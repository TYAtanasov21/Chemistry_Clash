#include "Scene.h"

//Scene::Scene(Color backgroundColor ) : backgroundColor(backgroundColor);

void Scene::LoadScene() {
	ClearBackground(backgroundColor);
	std::vector<Button> buttonV;
	for (auto itr = rectangleV.begin(); itr != rectangleV.end(); itr++) {
		//Button temp(*itr, "test", textSize,);
		//buttonV.push_back(*itr, )
	}
}

void Scene::AddRec(Rectangle rec) {
	rectangleV.push_back(rec);
}
void Scene::AddRec(int x, int y, int width, int height) {
	Rectangle rec = { x, y, width, height };
	rectangleV.push_back(rec);
}