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

void SceneManager::ChangeScene(std::string scene) {
    this->scene = nullptr;
    this->sceneString = scene;
}

void SceneManager::SetScene(std::shared_ptr<Scene> newScene) {
    this->scene = newScene;
}

std::shared_ptr<Scene> SceneManager::GetScene() {
    return this->scene;
}

std::string SceneManager::GetSceneString() {
    return this->sceneString;
}