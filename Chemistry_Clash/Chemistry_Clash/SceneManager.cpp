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

//template<typename SceneType>
void SceneManager::ChangeScene() {
	//auto newScene = std::make_shared<SceneType>();
	//scene = std::static_pointer_cast<Scene>(newScene);
	scene = std::make_shared<MainMenu>();
	UIManager::GetInstance()->UpdateLists();
	this->LoadScene();
}
