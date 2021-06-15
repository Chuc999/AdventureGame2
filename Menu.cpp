#include "Menu.h"

void Menu::mainMenu()
{
	screenWidth = 800;
	screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	InitAudioDevice();
	fxButton = LoadSound("resources/buttonfx.wav");
	button = LoadTexture("newgamebutton.png");
	frameHeight = (float)button.height / NUM_FRAMES;
	sourceRec = { 0,0,(float)button.width, frameHeight };
	btnBounds = { GetScreenWidth() / 2.0f - button.width / 2.0f, GetScreenHeight() / 2.0f - button.height / NUM_FRAMES / 2.0f, (float)button.width, frameHeight };
	mousePoint = { 0.0f,0.0f };

}

void Menu::update()
{
	mousePoint = GetMousePosition();
	btnAction = false;

	if (CheckCollisionPointRec(mousePoint, btnBounds))
	{
		if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
		{
			btnAction = true;
		}
	}
	else
	{
		btnState = 0;
	}

	if (btnAction)
	{
		PlaySound(fxButton);
	}

	sourceRec.y = btnState * frameHeight;
}

void Menu::draw()
{
	ClearBackground(GRAY);
	DrawTextureRec(button, sourceRec, Vector2 { btnBounds.x, btnBounds.y }, WHITE);
}

void Menu::DeInitialization()
{
	UnloadTexture(button);  // Unload button texture
	UnloadSound(fxButton);  // Unload sound

	CloseAudioDevice();     // Close audio device
}
