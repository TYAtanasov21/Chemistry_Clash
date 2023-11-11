#pragma once

#include <iostream>
#include "raylib.h"
#include "SceneManager.h"

class Player {
public:
	Player(int health, int strength, int speed, int armour);

	Image GetImage();

	void ResizeImage(int width, int height);

	Texture2D GetTexture();
	
	int GetHealth();

	int GetStrength();

	int	GetSpeed();

	int GetArmour();

	

private:

	Image playerImage = LoadImage("../assets/.png/The ecological captain.png");
	int health; 
	int strength;
	int speed;
	int armour;
	bool canJump=1;
};


