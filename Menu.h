#pragma once
#include "include/raylib.h"
#include <iostream>
#include <vector>

#define NUM_FRAMES 3

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

	int j = 0;

	float screenWidth;
	float screenHeight;

	int btnState = 0;
	bool btnAction = false;

	Vector2 mousePoint;

public:
	void mainMenu();
	void update();
	void draw();
	void DeInitialization();
};

