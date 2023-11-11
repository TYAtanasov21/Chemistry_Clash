#include "Game.h"

Player::Player(int health, int strength, int speed) {
	this->health = health;
	this->strength = strength;
	this->speed = speed;
}

Texture2D Player::GetTexture() { return playerTexture; }

int Player::GetHealth() { return health; }

int Player::GetStrength() { return strength; }

int Player::GetSpeed() { return speed; }
