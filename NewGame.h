#pragma once
#include "Menu.h"

class NewGame : protected Menu
{
protected:
	struct menuOptions
	{
		const char* two = "Linked List";
		const char* three = "Binary Tree";
		const char* four = "Hashing - Console Game";
		const char* five = "Adventure Game";
		const char* six = "Back";
	};

	struct rectangles
	{
		Rectangle textBox;
		Rectangle textBox2;
		Rectangle textBox3;
		Rectangle textBox4;
		Rectangle textBox5;
		Rectangle textBox6;
	};

	rectangles* recs = new rectangles();
	menuOptions* menu = new menuOptions();



public:
	bool newGame = true;
	void gameMenu();
	void update();
	void draw();
};

