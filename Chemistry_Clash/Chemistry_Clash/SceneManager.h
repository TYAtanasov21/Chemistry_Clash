#pragma once

#include "Scene.h"

class SceneManager {
public:

    static std::shared_ptr<SceneManager> GetInstance()
    {
        if (instance == nullptr)
            instance = std::make_shared<SceneManager>();

        return instance;
    }

    void LoadScene();

    void ChangeScene(std::string scene);

    void UpdateScene();

    void SetScene(std::shared_ptr<Scene> newScene);

    std::shared_ptr<Scene> GetScene();

    std::string GetSceneString();

private:

    static std::shared_ptr<SceneManager> instance;
    bool isSceneLoaded = 0;
    std::shared_ptr<Scene> scene;
    std::string sceneString;
};