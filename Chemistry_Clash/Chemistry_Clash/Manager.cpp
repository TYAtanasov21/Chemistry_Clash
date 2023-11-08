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
    std::vector<Button> buttonList ={
    { {(SCREEN_WIDTH - 300) / 2,  200, 300, 100}, "PLAY", 50, GRAY, BLACK },
    { {(SCREEN_WIDTH - 300) / 2, SCREEN_HEIGHT- 300, 300, 100}, "SETTINGS", 50, GRAY, BLACK },
    };
    scene->InitButtonList(buttonList);
    std::vector<Text> textList = {
        {"Chemestry Clash", 50, {(SCREEN_WIDTH - (float)MeasureText("Chemestry Clash", 50)) / 2, 50}}
    };
    scene->InitTextList(textList);
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
