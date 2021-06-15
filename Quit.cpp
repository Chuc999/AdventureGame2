#include "Quit.h"

void Quit::draw()
{
	screenWidth = 800.0f;
	screenHeight = 450.0f;

	quitRecs->textBox = { screenWidth / 2 - 100, 150, 190, 35 };
	quitRecs->textBox2 = { screenWidth / 2 - 100, 200, 210, 35 };
	mousePoint = { 0.0f,0.0f };

	while (quitMenuOpen)
	{
		// Update
		mousePoint = GetMousePosition();
		

		if (CheckCollisionPointRec(mousePoint, quitRecs->textBox))
		{
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				DrawText("HIT", (int)screenWidth / 2, 0, 40, BLACK);
				DrawRectangleRec(quitRecs->textBox, RED);
				exit(0);
			}
		}
		if (CheckCollisionPointRec(mousePoint, quitRecs->textBox2))
		{
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				DrawText("HIT", (int)screenWidth / 2, 0, 40, BLACK);
				DrawRectangleRec(quitRecs->textBox2, RED);
				quitMenuOpen = false;
			}
		}
		else
		{
			btnState = 0;
		}

		// Draw
		BeginDrawing();
		ClearBackground(BLANK);
		DrawText("Are you sure?", (int)quitRecs->textBox.x - 100, 0, 40, RED);
		DrawText(quit->yes, (int)quitRecs->textBox.x, (int)quitRecs->textBox.y, 40, MAROON);
		DrawText(quit->no, (int)quitRecs->textBox2.x, (int)quitRecs->textBox2.y, 40, MAROON);
		EndDrawing();
	}
}
