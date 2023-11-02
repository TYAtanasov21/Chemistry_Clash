#include "mainMenu.h"
#include "func.h"



mainMenu::mainMenu() {
    InitWindow(screenWidth, screenHeight, "Chemistry Clash");
    SetWindowIcon(logo);
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);

 
                makeButton({ (float)screenWidth / 2, (float)screenHeight / 2 }, "PLAY", 50, 200, 100, 5, LIGHTGRAY, BLACK, GRAY);
        EndDrawing();
    }
    CloseWindow();
}