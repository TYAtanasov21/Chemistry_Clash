#include "SceneChanger.h"

void LoadNewScene() {
    auto sceneManager = SceneManager::GetInstance();

    if (sceneManager->GetScene() != nullptr) return;

    std::string newScene = sceneManager->GetSceneString();

    if (newScene == "Main Menu")
        sceneManager->SetScene(std::make_shared<MainMenu>());


    if (newScene == "Settings")
        sceneManager->SetScene(std::make_shared<Settings>());


    if (newScene == "Play")
        sceneManager->SetScene(std::make_shared<Play>());

    //UIManager::GetInstance()->UpdateLists();
    sceneManager->LoadScene();
}