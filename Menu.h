#pragma once
#include "include/raylib.h"
#include <iostream>

using namespace std;

class Menu
{
protected:
	struct menuOptions
	{
		const char* one = "New Game";
		const char* two = "Load Game";
		const char* three = "Quit";
	};

	struct rectangles
	{
		Rectangle textBox;
		Rectangle textBox2;
		Rectangle textBox3;
	};

	rectangles* recs = new rectangles();
	menuOptions* menu = new menuOptions();

	float screenWidth;
	float screenHeight;

	int btnState = 0;


	Vector2 mousePoint;

public:
	bool mainMenuOpen = true;

	void mainMenu();
	void update();
	void draw();
	void DeInitialization();
};