#include "Scene.h"
#include "MainMenu.h"

void MainMenu::LoadScene(){
	ClearBackground(backgroundColor);
	for (auto itr = buttonList.begin(); itr != buttonList.end(); itr++) {
		itr->Draw();
	}
}