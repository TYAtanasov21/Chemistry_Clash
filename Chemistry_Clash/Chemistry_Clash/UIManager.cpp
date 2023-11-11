#include "UIManager.h"

std::shared_ptr<UIManager> UIManager::instance = nullptr;

void UIManager::AddButton(Button button) {
	this->buttonList.push_back(button);
}

void UIManager::AddCheckButton(CheckButton checkButton) {
	this->checkButtonList.push_back(checkButton);
}


void UIManager::AddText(Text text) {
	this->textList.push_back(text);
}

void UIManager::AddRec(Rectangle2 rec){
	this->rectangleList.push_back(rec);
}

void UIManager::UpdateAll() {
	for (auto button : buttonList) {
		button.Update();
	}
	for (auto checkButton : checkButtonList) {
		checkButton.Update();
	}
}

void UIManager::DrawAll() {
	for (auto rec : rectangleList) {
		DrawRectangleRec(rec.rec, rec.recColor);
	}
	for (auto button : buttonList) {
		button.Draw();
	}
	for (auto checkButton : checkButtonList) {
		checkButton.Draw();
	}
	for (auto text : textList) {
		text.Draw();
	}
}

void UIManager::UpdateLists() {
	buttonList.clear();
	textList.clear();
	checkButtonList.clear();
	rectangleList.clear();
}