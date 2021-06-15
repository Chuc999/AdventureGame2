#pragma once
#include "Menu.h"

class NewGame : protected Menu
{
protected:
	struct menuOptions
	{
		const char* one = "Linked List";
		const char* two = "Double Linked List";
		const char* three = "Binary Tree";
		const char* four = "Adventure Game";
		const char* five = "Back";
	};

	struct rectangles
	{
		Rectangle textBox;
		Rectangle textBox2;
		Rectangle textBox3;
		Rectangle textBox4;
		Rectangle textBox5;
	};

	rectangles* recs = new rectangles();
	menuOptions* menu = new menuOptions();

	bool newGame = true;

public:
	void gameMenu();
	void update();
	void draw();
};

