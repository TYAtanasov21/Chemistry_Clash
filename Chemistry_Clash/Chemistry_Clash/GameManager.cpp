#include "GameManager.h"

std::shared_ptr<GameManager> GameManager::instance = nullptr; 

Player::Player(int health, int strength, int speed, int armour) { // Initialize Player constructor
	this->health = health;
	this->strength = strength;
	this->speed = speed;
	this->armour = armour;
}

Image Player::GetImage() { return playerImage; } // Gets player image

void Player::ResizeImage(int width, int height) { // Resizes player image
	ImageResize(&playerImage, width, height);
}

Texture2D Player::GetTexture() { return LoadTextureFromImage(playerImage); } // Gets Texture2D from player image

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
Villain::Villain(int health, int strength, int armour) // Initializes Villain constructor
{
	this->health = health;
	this->strength = strength;
	this->armour = armour;

	SetRandomSeed(time(NULL));
	this->identifier = GetRandomValue(1, 3); // Choses random value between 1 and 3 for villain image

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

Image Villain::GetImage() { return villainImage; } // Gets villain image

void Villain::ResizeImage(int width, int height) { // Resizes villain image
	ImageResize(&villainImage, width, height);
}
Texture2D Villain::GetTexture() { return LoadTextureFromImage(villainImage); } // Gets Texture2D from villain image

int Villain::GetHealth() { return health; }

int Villain::GetStrength() { return strength; }

int Villain::GetArmour() { return armour; }

std::string Villain::GetVillainName() { return villainName; }

int Villain::GetIdentifier() { return identifier; } 



std::shared_ptr<Player> GameManager::GetPlayer() { // Gets instance from player class
	return this->player;
}

std::shared_ptr<Villain> GameManager::GetVillain() {  // Gets instance from villain class
	return this->villain;
}

Image GameManager::GetBackgroundImage() {
	return this->backgroundImage;
}

void GameManager::ResizeBackgroundImage() {
	ImageResize(&this->backgroundImage, SCREEN_WIDTH, SCREEN_HEIGHT);
}