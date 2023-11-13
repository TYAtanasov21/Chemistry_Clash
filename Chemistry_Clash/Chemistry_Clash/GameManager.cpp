#include "GameManager.h"
//Initialize player class

std::shared_ptr<GameManager> GameManager::instance = nullptr;

Player::Player(int health, int strength, int speed, int armour) {
	this->health = health;
	this->strength = strength;
	this->speed = speed;
	this->armour = armour;
}

Image Player::GetImage() { return playerImage; }

void Player::ResizeImage(int width, int height) {
	ImageResize(&playerImage, width, height);
}

Texture2D Player::GetTexture() { return LoadTextureFromImage(playerImage); }

int Player::GetHealth() { return health; }

int Player::GetStrength() { return strength; }

int Player::GetSpeed() { return speed; }

int Player::GetArmour() { return armour; }


void Player::SetHealth(int value) {
	this->health = value;
}

void Player::SetStrength(int value) {
	this->strength = value;
}

void Player::SetSpeed(int value) {
	this->speed = value;
}

void Player::SetArmour(int value) {
	this->armour = value;
}


//Initialize villian class
Villain::Villain(int health, int strength, int armour)
{
	this->health = health;
	this->strength = strength;
	this->armour = armour;

	SetRandomSeed(time(NULL));
	this->identifier = GetRandomValue(1, 3);

	if (identifier == 1)
	{
		villainImage = LoadImage("../assets/.png/The plastic invader.png");
		villainName = "PLASTIC INVADER";
	}
	if (identifier == 2)
	{
		villainImage = LoadImage("../assets/.png/The pollution creature.png");
		villainName = "POLLUTION CREATURE";
	}
	if (identifier == 3)
	{
		villainImage = LoadImage("../assets/.png/The soil demon.png");
		villainName = "SOIL DEMON";
	}
}

Image Villain::GetImage() { return villainImage; }

void Villain::ResizeImage(int width, int height) {
	ImageResize(&villainImage, width, height);
}
Texture2D Villain::GetTexture() { return LoadTextureFromImage(villainImage); }

int Villain::GetHealth() { return health; }

int Villain::GetStrength() { return strength; }

int Villain::GetArmour() { return armour; }

std::string Villain::GetVillainName() { return villainName; }

int Villain::GetIdentifier() { return identifier; }



std::shared_ptr<Player> GameManager::GetPlayer() {
	return this->player;
}

std::shared_ptr<Villain> GameManager::GetVillain() {
	return this->villain;
}

Image GameManager::GetBackgroundImage() {
	return this->backgroundImage;
}

void GameManager::ResizeBackgroundImage() {
	ImageResize(&this->backgroundImage, SCREEN_WIDTH, SCREEN_HEIGHT);
}