#pragma once
#include "include/raylib.h"
#include <iostream>

#define NUM_FRAMES 3

using namespace std;

class Menu
{
protected:
	struct menuOptions
	{
		string one = " New Game";
		string two = " Load Game";
		string three = " Quit";
	};

	int screenWidth;
	int screenHeight;
	Sound fxButton;
	Texture2D button;
	float frameHeight;
	Rectangle sourceRec;
	Rectangle btnBounds;
	int btnState = 0;
	bool btnAction = false;

	Vector2 mousePoint;

public:
	void mainMenu();
	void update();
	void draw();
	void DeInitialization();
};

