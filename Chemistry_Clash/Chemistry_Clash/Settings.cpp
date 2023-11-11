#include "Settings.h"

void Settings::LoadScene() {
	auto UIManager = UIManager::GetInstance();

	UIManager->AddCheckButton({ {(SCREEN_WIDTH - 500) / 2,  200, 500, 100}, "FULLSCREEN", 50, PURPLE, WHITE, BLACK, []() {}});

	UIManager->AddButton({ {(SCREEN_WIDTH - 300) / 2, 550, 300, 100}, "BACK", 50, PURPLE, BLACK, []() {
		SceneManager::GetInstance()->ChangeScene("Main Menu");
	} });

	UIManager->AddText({ "Chemistry Clash", 80, {(SCREEN_WIDTH - (float)MeasureText("Chemistry Clash", 80)) / 2, 50} });

	backgroundColor = LIGHTPURPLE;

}