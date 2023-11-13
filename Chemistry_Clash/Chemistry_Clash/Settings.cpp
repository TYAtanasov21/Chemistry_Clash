#include "Settings.h"

void Settings::LoadScene() {

	auto UIManager = UIManager::GetInstance();

	CheckButton* fullScreen = new CheckButton({ (SCREEN_WIDTH - 500) / 2,  200, 500, 100 }, "FULLSCREEN", 50, PURPLE, WHITE, BLACK,
		[UIManager]() {
			UIManager->ToggleFullScreen();
		}, UIManager->GetShouldFullscreen(), 1);
	UIManager->AddCheckButton(fullScreen);

	CheckButton* showFPS = new CheckButton({ (SCREEN_WIDTH - 500) / 2,  350, 500, 100 }, "SHOW FPS", 50, PURPLE, WHITE, BLACK,
		[UIManager]() {
			UIManager->ToggleFPS();
		}, UIManager->GetShouldFpsShow(),1);
	UIManager->AddCheckButton(showFPS);

	UIManager->AddButton({ {(SCREEN_WIDTH - 300) / 2, 550, 300, 100}, "BACK", 50, PURPLE, BLACK, []() {
		SceneManager::GetInstance()->ChangeScene("Main Menu");
	} });

	UIManager->AddText(new Text({ "Settings", 80, {(SCREEN_WIDTH - (float)MeasureText("Settings", 80)) / 2, 50}, BLACK }));

	backgroundColor = LIGHTPURPLE;

}