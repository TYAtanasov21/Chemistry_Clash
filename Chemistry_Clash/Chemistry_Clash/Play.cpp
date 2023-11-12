#include "Play.h"
#include "Manager.h"

void Play::LoadScene() {

	Player p(100, 10, 10, 50);

	auto UIManager = UIManager::GetInstance();

	UIManager->AddRec({ {20, 20, 300 , SCREEN_HEIGHT - 100 - 60}, PURPLE });
	UIManager->AddText({ "QUIZ", 60, {(SCREEN_WIDTH - (float)MeasureText("QUIZ", 60))/2, 20}, BLACK });
	UIManager->AddText({ "YOUR STATS", 33, {40 + (260 - (float)MeasureText("YOUR STATS", 33)) / 2, 40} , BLACK });

	std::string healthStatStringPlayer = "Health: " + std::to_string(p.GetHealth());
	std::string strengthStatStringPlayer = "Strength: " + std::to_string(p.GetStrength());
	std::string speedStatStringPlayer = "Speed: " + std::to_string(p.GetSpeed());
	std::string armourStatStringPlayer = "Armour: " + std::to_string(p.GetArmour());

	UIManager->AddText({ healthStatStringPlayer, 30, {40 + (260 - (float)MeasureText(healthStatStringPlayer.c_str(), 30)) / 2, 110} , BLACK,
		[&healthStatStringPlayer, &p]() {
		healthStatStringPlayer = "Health: " + std::to_string(p.GetHealth());
	} });
	UIManager->AddText({ strengthStatStringPlayer, 30, {40 + (260 - (float)MeasureText(strengthStatStringPlayer.c_str(), 30)) / 2, 150 } , BLACK,
		[&strengthStatStringPlayer, &p]() {
		strengthStatStringPlayer = "Health: " + std::to_string(p.GetStrength());
	} });

	UIManager->AddText({ speedStatStringPlayer, 30, {40 + (260 - (float)MeasureText(speedStatStringPlayer.c_str(), 30)) / 2, 190} , BLACK,
		[&speedStatStringPlayer, &p]() {
		speedStatStringPlayer = "Health: " + std::to_string(p.GetSpeed());
	} });
	UIManager->AddText({ armourStatStringPlayer, 30, {40 + (260 - (float)MeasureText(armourStatStringPlayer.c_str(), 30)) / 2, 230} , BLACK,
		[&armourStatStringPlayer, &p]() {
		armourStatStringPlayer = "Health: " + std::to_string(p.GetArmour());
	} });

	UIManager->AddButton({ {20 - 2.5, SCREEN_HEIGHT - 100 - 20, 300, 100}, "QUIT", 50, PURPLE, BLACK, []() {
		Manager::GetInstance()->Close(); 
	} });

	p.ResizeImage(240 * 3, 240 * 3);
	UIManager->AddTexture({ p.GetTexture(), {0, 0, (float)p.GetTexture().width / 3, (float)p.GetTexture().height / 3}, {40, 290} });


	Villain v(150, 15, 100);
	UIManager->AddRec({ {SCREEN_WIDTH - 320, 20, 300 , SCREEN_HEIGHT - 100 - 60}, PURPLE });
	UIManager->AddText({ "VILLAIN STATS", 33, {(SCREEN_WIDTH - 300) + (260 - (float)MeasureText("VILLAIN STATS", 33)) / 2, 40} , BLACK });

	std::string healthStatStringVillain = "Health: " + std::to_string(p.GetHealth());
	std::string strengthStatStringVillain = "Strength: " + std::to_string(p.GetStrength());
	std::string armourStatStringVillain = "Armour: " + std::to_string(p.GetArmour());

	UIManager->AddText({ healthStatStringVillain, 30, {(SCREEN_WIDTH - 300) + (260 - (float)MeasureText(healthStatStringVillain.c_str(), 30)) / 2, 110} , BLACK, []() {}});
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

	SetRandomSeed(time(NULL));
	int randomValue = GetRandomValue(1, 3);

	std::string questionString, answer;
	if (randomValue == 1) {
		questionString = "4P + _O2 -> 2P203";
		answer = "3";
	}
	if (randomValue == 2) {
		questionString = "2Ca + O2 -> _CaO";
		answer = "2";
	}
	if (randomValue == 3) {
		questionString = "4Al + 3O2 -> 2Al_O3";
		answer = "2";
	}

	std::string answer1 = answer;
	bool answeredCorrectly1;

	Text* text1 = new Text(questionString, 30, { 340, 110 }, BLACK);

	Input* input1 = new Input({ SCREEN_WIDTH - 430 - 100, 100, 80, 40 }, 30, PURPLE, BLACK, 1, 1, [answer1, &input1, &answeredCorrectly1]() {
		answeredCorrectly1 = input1->GetInputString() == answer1;
		});


	Button* button1 = new Button({ SCREEN_WIDTH - 340 - 100, 100, 100, 40 }, "Check", 30, PURPLE, BLACK, [&answeredCorrectly1, &button1, &input1, &p]() {
		input1->CallLambda();
		if (answeredCorrectly1) {
			p.SetArmour(p.GetArmour() + 10);
			std::cout << p.GetArmour();
		}
		input1->ToggleCanInput();
		button1->ToggleClicking();
		});

	Question* question1 = new Question(text1, answer, button1, input1, 40);
	UIManager->AddQuestion(question1);


	// -------------------------------------------------------------------------------------------------------------------

	SetRandomSeed(time(NULL));
	randomValue = GetRandomValue(1, 3);

	if (randomValue == 1) {
		questionString = "2P + _Cl2 -> 2PCL3";
		answer = "3";
	}
	if (randomValue == 2) {
		questionString = "Ca + Cl_ -> CaCl2";
		answer = "2";
	}
	if (randomValue == 3) {
		questionString = "2CO + O2 -> _CO2";
		answer = "2";
	}

	std::string answer2 = answer;
	bool answeredCorrectly2;

	Text* text2 = new Text(questionString, 30, { 340, 210 }, BLACK);

	Input* input2 = new Input({ SCREEN_WIDTH - 430 - 100, 200, 80, 40 }, 30, PURPLE, BLACK, 1, 1, [answer2, &input2, &answeredCorrectly2]() {
		answeredCorrectly2 = input2->GetInputString() == answer2;
		});


	Button* button2 = new Button({ SCREEN_WIDTH - 340 - 100, 200, 100, 40 }, "Check", 30, PURPLE, BLACK, [&answeredCorrectly2, &button2, &input2, &p]() {
		input2->CallLambda();
		if (answeredCorrectly2) {
			p.SetArmour(p.GetArmour() + 10);
			std::cout << p.GetArmour();
		}
		input2->ToggleCanInput();
		button2->ToggleClicking();
		});

	Question* question2 = new Question(text2, answer, button2, input2, 40);
	UIManager->AddQuestion(question2);
// -------------------------------------------------------------------------------------------------------------------

	SetRandomSeed(time(NULL));
	randomValue = GetRandomValue(1, 3);


	if (randomValue == 1) {
		questionString = "S + H2 -> H_S";
		answer = "2";
	}
	if (randomValue == 2) {
		questionString = "_S + 3O2 -> 2SO3";
		answer = "2";
	}
	if (randomValue == 3) {
		questionString = "2K + S -> K_S";
		answer = "2";
	}


	std::string answer3 = answer;
	bool answeredCorrectly3;

	Text* text3 = new Text(questionString, 30, { 340, 310 }, BLACK);

	Input* input3 = new Input({ SCREEN_WIDTH - 430 - 100, 300, 80, 40 }, 30, PURPLE, BLACK, 1, 1, [answer3, &input3, &answeredCorrectly3]() {
		answeredCorrectly3 = input3->GetInputString() == answer3;
		});


	Button* button3 = new Button({ SCREEN_WIDTH - 340 - 100, 300, 100, 40 }, "Check", 30, PURPLE, BLACK, [&answeredCorrectly3, &button3, &input3, &p]() {
		input3->CallLambda();
		if (answeredCorrectly3) {
			p.SetArmour(p.GetArmour() + 10);
			std::cout << p.GetArmour();
		}
		input3->ToggleCanInput();
		button3->ToggleClicking();
		});

	Question* question3 = new Question(text3, answer, button3, input3, 40);
	UIManager->AddQuestion(question3);

// -------------------------------------------------------------------------------------------------------------------

	SetRandomSeed(time(NULL));
	randomValue = GetRandomValue(1, 3);

	if (randomValue == 1) {
		questionString = "2Al + _Cl2 -> 2AlCl3";
		answer = "3";
	}
	if (randomValue == 2) {
		questionString = "Al + HCl -> AlCl_ + H2";
		answer = "3";
	}
	if (randomValue == 3) {
		questionString = "2H2 + O_ -> 2H2O";
		answer = "2";
	}

	std::string answer4 = answer;
	bool answeredCorrectly4;

	Text* text4 = new Text(questionString, 30, { 340, 410 }, BLACK);

	Input* input4 = new Input({ SCREEN_WIDTH - 430 - 100, 400, 80, 40 }, 30, PURPLE, BLACK, 1, 1, [answer4, &input4, &answeredCorrectly4]() {
		answeredCorrectly4 = input4->GetInputString() == answer4;
		});


	Button* button4 = new Button({ SCREEN_WIDTH - 340 - 100, 400, 100, 40 }, "Check", 30, PURPLE, BLACK, [&answeredCorrectly4, &button4, &input4, &p]() {
		input4->CallLambda();
		if (answeredCorrectly4) {
			p.SetArmour(p.GetArmour() + 10);
			std::cout << p.GetArmour();
		}
			input4->ToggleCanInput();
			button4->ToggleClicking();
		});

	Question* question4 = new Question(text4, answer, button4, input4, 40);
	UIManager->AddQuestion(question4);

	backgroundColor = LIGHTPURPLE;
}

