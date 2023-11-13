#include "SceneChanger.h"

void LoadNewScene() {
    auto sceneManager = SceneManager::GetInstance();

    if (sceneManager->GetScene() != nullptr) return;

    std::string newScene = sceneManager->GetSceneString();

    if (newScene == "Main Menu")
        sceneManager->SetScene(std::make_shared<MainMenu>()); // Changes current scene to Main Menu


    if (newScene == "Settings")
        sceneManager->SetScene(std::make_shared<Settings>()); // Changes current scene to Settings


    if (newScene == "Play")
        sceneManager->SetScene(std::make_shared<Play>()); // Changes current scene to Play Menu

    sceneManager->LoadScene();
}