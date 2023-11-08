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
    std::vector<Button> test ={
    { {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 200, 100}, "PLAY", 50, GRAY, BLACK },
    { {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2+ 200, 200, 100}, "PLAY", 50, GRAY, BLACK },
};
    scene->InitButtonList(test);
    InitScene(scene, scene->GetButtonList(), LIGHTGRAY);
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
