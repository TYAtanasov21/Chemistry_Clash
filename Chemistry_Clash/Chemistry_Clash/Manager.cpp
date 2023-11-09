#include "Manager.h"

std::shared_ptr<Manager> Manager::instance = nullptr;

Manager::~Manager()
{
    CloseWindow();
}

void Manager::Initialize()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);
    //Set window's logo
    Image img = LoadImage("../assets/Logo.png");
    SetWindowIcon(img);
    //ToggleFullscreen();
    SetTargetFPS(60);
    Start();
}

void Manager::Start()
{
    scene->SetBackgroundColor(LIGHTGRAY);

    scene->AddButton({ {(SCREEN_WIDTH - 300) / 2,  200, 300, 100}, "PLAY", 50, GRAY, BLACK, []() {} });
    scene->AddButton({ {(SCREEN_WIDTH - 300) / 2, 375, 300, 100}, "SETTINGS", 50, GRAY, BLACK, []() {} });
    scene->AddButton({ {(SCREEN_WIDTH - 300) / 2, 550, 300, 100}, "QUIT", 50, GRAY, BLACK, [this]() { this->Close(); } });
    
    scene->AddText({ "Chemestry Clash", 80, {(SCREEN_WIDTH - (float)MeasureText("Chemestry Clash", 80)) / 2, 50} });
    
}

void Manager::Update()
{
    BeginDrawing();
    scene->LoadScene();
    EndDrawing();
}

bool Manager::ShouldWindowClose()
{
    return WindowShouldClose() || shouldWindowClose;
}

void Manager::Close()
{
    shouldWindowClose = true;
}
