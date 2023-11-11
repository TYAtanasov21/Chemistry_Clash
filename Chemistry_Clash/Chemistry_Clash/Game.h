#pragma once

#include <iostream>
#include "raylib.h"
#include "SceneManager.h"

class Player {
public:
	Player(int health, int strength, int speed);

	Texture2D GetTexture();
	
	int GetHealth();

	int GetStrength();

	int	GetSpeed();


private:
	Texture2D playerTexture = LoadTexture("assets\.png\The-ecological-captain.png");
	int health; 
	int strength;
	int speed;
	int armour;
	bool canJump=1;
};


