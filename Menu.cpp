#include "Menu.h"
#include "raylib.h"
#include "Quit.h"

void Menu::mainMenu()
{
	
	screenWidth = 800.0f;
	screenHeight = 450.0f;

	InitWindow((int)screenWidth, (int)screenHeight, "MAIN MENU - Test One");

	InitAudioDevice();
	recs->textBox = { screenWidth / 2 - 100, 150, 190, 35 };
	recs->textBox2 = { screenWidth / 2 - 100, 200, 210, 35 };
	recs->textBox3 = { screenWidth / 2 - 100, 250, 100, 35 };
	mousePoint = { 0.0f,0.0f };
}

void Menu::update()
{
	mousePoint = GetMousePosition();

	if (CheckCollisionPointRec(mousePoint, recs->textBox))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			DrawText("HIT", (int)screenWidth / 2, 0, 40, BLACK);
			DrawRectangleRec(recs->textBox, RED);
		}
	}
	if (CheckCollisionPointRec(mousePoint, recs->textBox2))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			DrawText("HIT", (int)screenWidth / 2, 0, 40, BLACK);
			DrawRectangleRec(recs->textBox2, RED);
		}
	}
	if (CheckCollisionPointRec(mousePoint, recs->textBox3))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{	
			Quit* quit = new Quit();
			mainMenuOpen = false;
			quit->draw();
		}
	}
	else
	{
		btnState = 0;
	}

	
}

void Menu::draw()
{	
	ClearBackground(GRAY);
	DrawText(menu->one, (int)recs->textBox.x, (int)recs->textBox.y, 40, MAROON);
	DrawText(menu->two, (int)recs->textBox2.x, (int)recs->textBox2.y, 40, MAROON);
	DrawText(menu->three, (int)recs->textBox3.x, (int)recs->textBox3.y, 40, MAROON);
}

void Menu::DeInitialization()
{
	
	CloseAudioDevice();     // Close audio device
}
