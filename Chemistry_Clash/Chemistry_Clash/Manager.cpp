#include "Manager.h"

std::shared_ptr<Manager> Manager::instance = nullptr;

Manager::~Manager()
{
    CloseWindow();
}

void Manager::Initialize()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

    //ToggleFullscreen();

    SetTargetFPS(60);

    Start();
}

void Manager::Start()
{
    
}

void Manager::Update()
{
    BeginDrawing();
    button.Draw();
    ClearBackground(BLUE);
    EndDrawing();
    if (button.IsClicked()) {
        Close();
    }
}

bool Manager::ShouldWindowClose()
{
    return WindowShouldClose() || shouldWindowClose;
}

void Manager::Close()
{
    shouldWindowClose = true;
}
