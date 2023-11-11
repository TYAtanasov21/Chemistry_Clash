#include "SceneManager.h"

std::shared_ptr<SceneManager> SceneManager::instance = nullptr;

void SceneManager::LoadScene() {
    if (!isSceneLoaded) {
        UIManager::GetInstance()->UpdateLists();
        scene->LoadScene();
        isSceneLoaded = 1;

    }

}

void SceneManager::UpdateScene() {
    scene->ClearSceneBackground();
    UIManager::GetInstance()->DrawAll();
    UIManager::GetInstance()->UpdateAll();
}

void SceneManager::ChangeScene(std::string scene) {
    isSceneLoaded = 0;
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