#include <iostream>
#include "raylib.h"
int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    Image logo = LoadImage("images/Logo.png");
    InitWindow(screenWidth, screenHeight, "basic window");
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