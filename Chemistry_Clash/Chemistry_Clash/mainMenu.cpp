#include "mainMenu.h"


mainMenu::mainMenu() {
    InitWindow(screenWidth, screenHeight, "Chemistry Clash");
    SetWindowIcon(logo);
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();
}