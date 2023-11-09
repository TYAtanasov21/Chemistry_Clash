#include "Scene.h"
#include "MainMenu.h"

void MainMenu::LoadScene(){
	ClearBackground(backgroundColor);
	for (auto itr = buttonList.begin(); itr != buttonList.end(); itr++) {
		itr->Draw();
		if (itr->IsClicked()) {
			itr->GetLambda()();
		}
	}
	for (auto itr = textList.begin(); itr != textList.end(); itr++) {
		itr->Draw();
	}
}