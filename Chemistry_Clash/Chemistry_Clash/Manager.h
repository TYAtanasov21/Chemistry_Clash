#pragma once

#include <cstdint>
#include <raylib.h>

#include "Macro.h"
#include "SceneChanger.h"

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

    bool shouldWindowClose = 0;

};