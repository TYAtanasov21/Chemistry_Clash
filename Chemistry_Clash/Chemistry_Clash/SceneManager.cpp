#include "SceneManager.h"

std::shared_ptr<SceneManager> SceneManager::instance = nullptr;

void SceneManager::LoadScene() {
	scene->LoadScene();
}

void SceneManager::UpdateScene() {
	scene->ClearSceneBackground();
	UIManager::GetInstance()->DrawAll();
	UIManager::GetInstance()->UpdateAll();
}

//template<class SceneType>
void SceneManager::ChangeScene(std::shared_ptr<Scene> sceneType) {
	this->scene = sceneType;
	UIManager::GetInstance()->UpdateLists();
	this->LoadScene();
}

