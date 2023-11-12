#include "Play.h"

void Play::LoadScene() {

	Player p(100, 10, 10, 50);

	auto UIManager = UIManager::GetInstance();

	UIManager->AddRec({ {20, 20, 300 , SCREEN_HEIGHT - 100 - 60}, PURPLE });

	UIManager->AddText({ "YOUR STATS", 33, {40 + (260 - (float)MeasureText("YOUR STATS", 33)) / 2, 40} , BLACK });

	std::string healthStatStringPlayer = "Health: " + std::to_string(p.GetHealth());
	std::string strengthStatStringPlayer = "Strength: " + std::to_string(p.GetStrength());
	std::string speedStatStringPlayer = "Speed: " + std::to_string(p.GetSpeed());
	std::string armourStatStringPlayer = "Armour: " + std::to_string(p.GetArmour());

	UIManager->AddText({ healthStatStringPlayer, 30, {40 + (260 - (float)MeasureText(healthStatStringPlayer.c_str(), 30)) / 2, 110} , BLACK });
	UIManager->AddText({ strengthStatStringPlayer, 30, {40 + (260 - (float)MeasureText(strengthStatStringPlayer.c_str(), 30)) / 2, 150 } , BLACK });
	UIManager->AddText({ speedStatStringPlayer, 30, {40 + (260 - (float)MeasureText(speedStatStringPlayer.c_str(), 30)) / 2, 190} , BLACK });
	UIManager->AddText({ armourStatStringPlayer, 30, {40 + (260 - (float)MeasureText(armourStatStringPlayer.c_str(), 30)) / 2, 230} , BLACK });

	UIManager->AddButton({ {20 - 2.5, SCREEN_HEIGHT - 100 - 20, 300, 100}, "BACK", 50, PURPLE, BLACK, []() {
		SceneManager::GetInstance()->ChangeScene("Main Menu");
	} });

	p.ResizeImage(240 * 3, 240 * 3);
	UIManager->AddTexture({ p.GetTexture(), {0, 0, (float)p.GetTexture().width / 3, (float)p.GetTexture().height / 3}, {40, 290} });


	Villain v(150, 15, 100);
	UIManager->AddRec({ {SCREEN_WIDTH - 320, 20, 300 , SCREEN_HEIGHT - 100 - 60}, PURPLE });
	UIManager->AddText({ "VILLAIN STATS", 33, {(SCREEN_WIDTH - 300) + (260 - (float)MeasureText("VILLAIN STATS", 33)) / 2, 40} , BLACK });

	std::string healthStatStringVillain = "Health: " + std::to_string(p.GetHealth());
	std::string strengthStatStringVillain = "Strength: " + std::to_string(p.GetStrength());
	std::string armourStatStringVillain = "Armour: " + std::to_string(p.GetArmour());

	UIManager->AddText({ healthStatStringVillain, 30, {(SCREEN_WIDTH - 300) + (260 - (float)MeasureText(healthStatStringVillain.c_str(), 30)) / 2, 110} , BLACK });
	UIManager->AddText({ strengthStatStringVillain, 30, {(SCREEN_WIDTH - 300) + (260 - (float)MeasureText(strengthStatStringVillain.c_str(), 30)) / 2, 150 } , BLACK });
	UIManager->AddText({ armourStatStringVillain, 30, {(SCREEN_WIDTH - 300) + (260 - (float)MeasureText(armourStatStringVillain.c_str(), 30)) / 2, 190} , BLACK });

	if (v.GetIdentifier() == 1)
	{
		v.ResizeImage(240 * 3, 240 * 2);
		UIManager->AddTexture({ v.GetTexture(), {0, 0, (float)v.GetTexture().width / 3, (float)v.GetTexture().height / 2}, {(SCREEN_WIDTH - 290), 290} });
	}
	else
	{
		v.ResizeImage(240 * 3, 240);
		UIManager->AddTexture({ v.GetTexture(), {0, 0, (float)v.GetTexture().width / 3, (float)v.GetTexture().height}, {(SCREEN_WIDTH - 290), 290} });
	}

	UIManager->AddButton({ {(SCREEN_WIDTH - 320) - 2.5, SCREEN_HEIGHT - 120, 300, 100}, "FIGHT!", 50, PURPLE, BLACK, []() {} });


	/*Questions*/

	Text* text1= new Text("4P + _O2 -> 2P203", 40, { 340, 105 }, BLACK);
	Button* button1 = new Button({ SCREEN_WIDTH - 340 - 100, 100, 100, 40 }, "Check", 30, PURPLE, BLACK, []() {});
	Input* input1= new Input({ SCREEN_WIDTH - 450 - 100, 100, 100, 40 }, 30, PURPLE, BLACK, 1, 1, []() {});

	Question* question1 = new Question(text1, "3", button1, input1, 40);
	UIManager->AddQuestion(question1);

	// -------------------------------------------------------------------------------------------------------------------

	Text* text2 = new Text("4P + _O2 -> 2P203", 40, { 340, 165 }, BLACK);
	Button* button2 = new Button({ SCREEN_WIDTH - 340 - 100, 160, 100, 40 }, "Check", 30, PURPLE, BLACK, []() {});
	Input* input2 = new Input({ SCREEN_WIDTH - 450 - 100, 160, 100, 40 }, 30, PURPLE, BLACK, 1, 1, []() {});

	Question* question2 = new Question(text2, "3", button2, input2, 40);
	UIManager->AddQuestion(question2);

// -------------------------------------------------------------------------------------------------------------------

	Text* text3 = new Text("4P + _O2 -> 2P203", 40, { 340, 225 }, BLACK);
	Button* button3 = new Button({ SCREEN_WIDTH - 340 - 100, 220, 100, 40 }, "Check", 30, PURPLE, BLACK, []() {});
	Input* input3 = new Input({ SCREEN_WIDTH - 450 - 100, 220, 100, 40 }, 30, PURPLE, BLACK, 1, 1, []() {});

	Question* question3 = new Question(text3, "3", button3, input3, 40);
	UIManager->AddQuestion(question3);

// -------------------------------------------------------------------------------------------------------------------

	Text* text4 = new Text("4P + _O2 -> 2P203", 40, { 340, 285 }, BLACK);
	Button* button4 = new Button({ SCREEN_WIDTH - 340 - 100, 280, 100, 40 }, "Check", 30, PURPLE, BLACK, []() {});
	Input* input4 = new Input({ SCREEN_WIDTH - 450 - 100, 280, 100, 40 }, 30, PURPLE, BLACK, 1, 1, []() {});

	Question* question4 = new Question(text4, "3", button4, input4, 40);
	UIManager->AddQuestion(question4);

// -------------------------------------------------------------------------------------------------------------------

	Text* text5 = new Text("4P + _O2 -> 2P203", 40, { 340, 345 }, BLACK);
	Button* button5 = new Button({ SCREEN_WIDTH - 340 - 100, 340, 100, 40 }, "Check", 30, PURPLE, BLACK, []() {});
	Input* input5 = new Input({ SCREEN_WIDTH - 450 - 100, 340, 100, 40 }, 30, PURPLE, BLACK, 1, 1, []() {});

	Question* question5 = new Question(text5, "3", button5, input5, 40);
	UIManager->AddQuestion(question5);
	//Input input1({ 400,200,100,100 }, 40, PURPLE, BLACK, 1, 1, []() {});
	//UIManager->AddInput(&input1);

	

	backgroundColor = LIGHTPURPLE;
}

