#pragma once

#include <iostream>
#include <stdlib.h>
#include "raylib.h"
#include "SceneManager.h"

class Player {
public:
	Player(int health, int strength, int speed, int armour); // Declare constructor for Player with base stats

	Image GetImage(); // Gets playerImage

	void ResizeImage(int width, int height); // Resizes playerImage

	Texture2D GetTexture(); // Gets playerImage as Texture2D
	
	int GetHealth(); 

	int GetStrength();

	int	GetSpeed();

	int GetArmour();

	void SetHealth(int value);

	void SetStrength(int value);

	void SetSpeed(int value);

	void SetArmour(int value);

private:

	Image playerImage = LoadImage("../assets/.png/The ecological captain.png");
	int health; 
	int strength;
	int speed;
	int armour;
	bool canJump=1;
};

class Villain {
public:
	Villain(int health, int strength, int armour); // Declare constructor for Villain with base stats

	Image GetImage(); // Gets villainImage

	void ResizeImage(int width, int height); // Resizes villainImage

	Texture2D GetTexture(); // Gets villainImage as Texture2D

	int GetHealth();

	int GetStrength();

	int GetArmour();
	
	std::string GetVillainName();

	int GetIdentifier();
private:

	Image villainImage;
	int health;
	int strength;
	int armour;
	int identifier;
	std::string villainName;
};

class GameManager { // GameManager Singleton
public:
	static std::shared_ptr<GameManager> GetInstance()
	{
		if (instance == nullptr)
			instance = std::make_shared<GameManager>();

		return instance;
	}

	std::shared_ptr<Player> GetPlayer();
	std::shared_ptr<Villain> GetVillain();

	Image GetBackgroundImage();
	void ResizeBackgroundImage();

private:
	static std::shared_ptr<GameManager> instance;


	std::shared_ptr<Player> player = std::make_shared<Player>(100, 10, 10, 50);
	std::shared_ptr<Villain> villain = std::make_shared<Villain>(150, 15, 50);

	Image backgroundImage = LoadImage("../assets/Background.jpg");

};