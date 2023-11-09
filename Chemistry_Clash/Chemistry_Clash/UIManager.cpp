#include "UIManager.h"

std::shared_ptr<UIManager> UIManager::instance = nullptr;

void UIManager::AddButton(Button button) {
	this->buttonList.push_back(button);
}

void UIManager::AddText(Text text) {
	this->textList.push_back(text);
}

void UIManager::UpdateAll() {
	for (auto button : buttonList) {
		button.Update();
	}
}

void UIManager::DrawAll() {
	for (auto button : buttonList) {
		button.Draw();
	}
	for (auto text : textList) {
		text.Draw();
	}
}

void UIManager::UpdateLists() {
	buttonList.clear();
	textList.clear();
}