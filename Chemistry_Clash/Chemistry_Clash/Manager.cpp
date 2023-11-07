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
    Rectangle tempRec = { (SCREEN_WIDTH-200) / 2, (SCREEN_HEIGHT-100) / 2, 200, 100 };
    std::vector<Button> tempButton = { {tempRec , "Text", 40, RED, BLUE}  };
    scene->InitButtonList(tempButton);
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
