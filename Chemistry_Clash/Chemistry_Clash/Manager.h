#pragma once
#include <cstdint>
#include <raylib.h>
#include <memory>
#include "Button.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define SCREEN_TITLE "Chemistry Clash"

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

    Rectangle rec = {500, 300, 200, 100};
    Button button = {rec, "Hello", 50, RED, WHITE};
};