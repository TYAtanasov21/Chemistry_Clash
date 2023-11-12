#include "Question.h"
#include "UIManager.h"

Question::Question(Text* question, std::string answer, Button* check, Input* answerField, int textSize){
	this->question = question;
	this->answer = answer;
	this->check = check;
	this->answerField = answerField;
}

void Question::Draw() {
	question->Draw();
	check->Draw();
	answerField->Draw();
}

void Question::Update() {
	check->Update();
	answerField->Update();
}