#include "NewGame.h"
#include "Node.h"

void NewGame::gameMenu()
{
	screenWidth = 800.0f;
	screenHeight = 450.0f;

	SetWindowSize((int)screenWidth, (int)screenHeight);

	recs->textBox2 = { screenWidth / 2 - 130, 150, 220, 35 };
	recs->textBox3 = { screenWidth / 2 - 130, 200, 220, 35 };
	recs->textBox4 = { screenWidth / 2 - 130, 250, 300, 35 };
	recs->textBox5 = { screenWidth / 2 - 130, 300, 200, 35 };
	recs->textBox6 = { screenWidth / 2 - 130, 350, 100, 35 };
	mousePoint = { 0.0f,0.0f };

	while (newGame)
	{
		NewGame::update();

		NewGame::draw();
	}
}

void NewGame::update()
{
	mousePoint = GetMousePosition();

	if (CheckCollisionPointRec(mousePoint, recs->textBox2))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			newGame = false;
			Node* node = new Node();
			node->init();
		}
	}
	if (CheckCollisionPointRec(mousePoint, recs->textBox3))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			DrawText("HIT", (int)screenWidth / 2, 0, 40, BLACK);
			DrawRectangleRec(recs->textBox3, RED);
		}
	}
	if (CheckCollisionPointRec(mousePoint, recs->textBox4))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			DrawText("HIT", (int)screenWidth / 2, 0, 40, BLACK);
			DrawRectangleRec(recs->textBox4, RED);
		}
	}
	if (CheckCollisionPointRec(mousePoint, recs->textBox5))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			DrawText("HIT", (int)screenWidth / 2, 0, 40, BLACK);
			DrawRectangleRec(recs->textBox5, RED);			
		}
	}
	if (CheckCollisionPointRec(mousePoint, recs->textBox6))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			DrawText("HIT", (int)screenWidth / 2, 0, 40, BLACK);
			DrawRectangleRec(recs->textBox5, RED);
			newGame = false;
		}
	}
}

void NewGame::draw()
{
	BeginDrawing();
	ClearBackground(BLANK);
	DrawText("What do you want to play?", (int)recs->textBox2.x - 130, 0, 40, RED);
	DrawText(menu->two, (int)recs->textBox2.x, (int)recs->textBox2.y, 40, MAROON);
	DrawText(menu->three, (int)recs->textBox3.x, (int)recs->textBox3.y, 40, MAROON);
	DrawText(menu->four, (int)recs->textBox4.x, (int)recs->textBox4.y, 40, MAROON);
	DrawText(menu->five, (int)recs->textBox5.x, (int)recs->textBox5.y, 40, MAROON);
	DrawText(menu->six, (int)recs->textBox6.x, (int)recs->textBox6.y, 40, MAROON);
	EndDrawing();
}