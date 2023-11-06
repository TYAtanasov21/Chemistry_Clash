#include "SceneManager.h"

SceneManager::SceneManager(Scene* scene) {
	this->scene = scene;
}

Scene* SceneManager::operator->() {
	return this->scene;
}