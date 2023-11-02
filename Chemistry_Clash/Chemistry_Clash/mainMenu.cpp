#include "mainMenu.h"
#include "colours.h"
mainMenu::mainMenu() {
    colours* c = new colours;
    InitWindow(screenWidth, screenHeight, "Chemistry Clash");
    SetWindowIcon(logo);
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(c->getColour("darkBlue"));
        DrawText("Chemistry clash", 190, 200, 60, LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();
}