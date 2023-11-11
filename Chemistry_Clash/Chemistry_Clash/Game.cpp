#include "Game.h"

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