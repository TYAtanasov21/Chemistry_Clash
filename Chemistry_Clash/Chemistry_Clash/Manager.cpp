#include "Manager.h"

std::shared_ptr<Manager> Manager::instance = nullptr;

Manager::~Manager()
{
    CloseWindow();
}

void Manager::Initialize()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

    Image img = LoadImage("../assets/Logo.png");
    SetWindowIcon(img);
    //ToggleFullscreen();
    SetTargetFPS(60);
    Start();
}

void Manager::Start()
{
    SceneManager::GetInstance()->ChangeScene("Main Menu");
}

void Manager::Update()
{
    BeginDrawing();

    LoadNewScene();
    SceneManager::GetInstance()->UpdateScene();

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