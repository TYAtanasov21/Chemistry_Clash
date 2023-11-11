#include "Play.h"

void Play::LoadScene() {

	Player p(100, 10, 10);

	auto UIManager = UIManager::GetInstance();

	UIManager->AddRec({ {20, 20, 300 , SCREEN_HEIGHT - 100 - 60}, PURPLE });

	UIManager->AddText({ "STATS", 50, {40 + (260 - (float)MeasureText("STATS", 50)) / 2, 40} , BLACK});

	std::string healthStatString = "Health: " + std::to_string(p.GetHealth());
	std::string strengthStatString = "Strength: " + std::to_string(p.GetStrength());
	std::string speedStatString = "Speed: " + std::to_string(p.GetSpeed());

	UIManager->AddText({ healthStatString, 30, {40 + (260 - (float)MeasureText(healthStatString.c_str(), 30)) / 2, 110} , BLACK});
	UIManager->AddText({ strengthStatString, 30, {40 + (260 - (float)MeasureText(strengthStatString.c_str(), 30)) / 2, 160 } , BLACK });
	UIManager->AddText({ speedStatString, 30, {40 + (260 - (float)MeasureText(speedStatString.c_str(), 30)) / 2, 210} , BLACK });

	UIManager->AddButton({ {20 - 2.5, SCREEN_HEIGHT - 100 - 20, 300, 100}, "BACK", 50, PURPLE, BLACK, []() {
	SceneManager::GetInstance()->ChangeScene("Main Menu");
	} });



	backgroundColor = LIGHTPURPLE;

}