#pragma once
#include "Menu.h"
class Quit : protected Menu
{
protected:
	struct QuitOption
	{
		const char* yes = { "YES" };
		const char* no = { "NO" };
	};

	struct rectangles
	{
		Rectangle textBox;
		Rectangle textBox2;
	};

	QuitOption* quit = new QuitOption();
	rectangles* quitRecs = new rectangles();
	bool quitMenuOpen = true;
public:
	void draw();
};

