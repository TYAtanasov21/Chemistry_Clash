#pragma once
#include <cstdint>
#include <raylib.h>
#include <memory>
#include "Button.h"
#include "Scene.h"
#include "Macro.h"
#include "MainMenu.h"

class Manager
{
public:
    ~Manager();

    static std::shared_ptr<Manager> GetInstance()
    {
        if (instance == nullptr)
            instance = std::make_shared<Manager>();

        return instance;
    }

    void Initialize();

    void Start();

    void Update();

    bool ShouldWindowClose();

    void Close(); 

private:
    static std::shared_ptr<Manager> instance;

    bool shouldWindowClose = false;

    Scene* scene = new MainMenu();
};