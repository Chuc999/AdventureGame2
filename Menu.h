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

	rectangles* recsMain = new rectangles();
	menuOptions* menu = new menuOptions();

	float screenWidth = 800.0f;
	float screenHeight = 450.0f;

	Vector2 mousePoint = { 0.0f,0.0f };

public:
	void mainMenu();
	void update();
	void draw();
	void DeInitialization();
};