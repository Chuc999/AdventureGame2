#include "Menu.h"
#include "raylib.h"
#include "Quit.h"
#include "NewGame.h"

void Menu::mainMenu()
{
	InitWindow((int)screenWidth, (int)screenHeight, "MAIN MENU - Test One");

	InitAudioDevice();
	recsMain->textBox = { 50, 400, 190, 35 };
	recsMain->textBox2 = { 350, 400, 210, 35 };
	recsMain->textBox3 = { 700, 400, 100, 35 };

}

void Menu::update()
{
	mousePoint = GetMousePosition();

	if (CheckCollisionPointRec(mousePoint, recsMain->textBox))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			DrawText("HIT", (int)screenWidth / 2, 0, 40, BLACK);
			DrawRectangleRec(recsMain->textBox, RED);
			NewGame* newGame = new NewGame();
			newGame->gameMenu();
		}
	}
	if (CheckCollisionPointRec(mousePoint, recsMain->textBox2))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			
		}
	}
	if (CheckCollisionPointRec(mousePoint, recsMain->textBox3))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{	
			Quit* quit = new Quit();			
			quit->draw();
		}
	}
}

void Menu::draw()
{	
	//ClearBackground(RAYWHITE);
	DrawText(menu->one, (int)recsMain->textBox.x, (int)recsMain->textBox.y, 40, MAROON);
	DrawText(menu->two, (int)recsMain->textBox2.x, (int)recsMain->textBox2.y, 40, MAROON);
	DrawText(menu->three, (int)recsMain->textBox3.x, (int)recsMain->textBox3.y, 40, MAROON);
}

void Menu::DeInitialization()
{	
	CloseAudioDevice();     // Close audio device
}
