#pragma once

#include "MainMenu.h"

class SceneManager {
public:

    static std::shared_ptr<SceneManager> GetInstance()
    {
        if (instance == nullptr)
            instance = std::make_shared<SceneManager>();

        return instance;
    }

	void LoadScene();

    //template<class SceneType>
    void ChangeScene(std::shared_ptr<Scene> sceneType);

    void UpdateScene();

private:

    static std::shared_ptr<SceneManager> instance;

	std::shared_ptr<Scene> scene;

};