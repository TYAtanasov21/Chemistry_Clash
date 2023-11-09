#include "MainMenu.h"

void MainMenu::LoadScene(){
	auto UIManager = UIManager::GetInstance();

	UIManager->AddButton({ {(SCREEN_WIDTH - 300) / 2,  200, 300, 100}, "PLAY", 50, GRAY, BLACK, []() {} });
	UIManager->AddButton({ {(SCREEN_WIDTH - 300) / 2, 375, 300, 100}, "SETTINGS", 50, GRAY, BLACK, []() {} });
	UIManager->AddButton({ {(SCREEN_WIDTH - 300) / 2, 550, 300, 100}, "QUIT", 50, GRAY, BLACK, []() {} });

	UIManager->AddText({ "Chemistry Clash", 80, {(SCREEN_WIDTH - (float)MeasureText("Chemistry Clash", 80)) / 2, 50} });

	backgroundColor = LIGHTGRAY;

}