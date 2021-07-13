#include "BinaryTree.h"


void BinaryTree::init()
{
	screenWidth = 800.0f;
	screenHeight = 600.0f;

	SetWindowSize((int)screenWidth, (int)screenHeight);

	BeginDrawing();
	ClearBackground(BLANK);
	EndDrawing();

	while (binaryGame)
	{
		BinaryTree::update();
		BinaryTree::Draw();
	}
}

void BinaryTree::update()
{
	Tree* root = new Tree(1);

	root->left = new Tree(2);
	root->right = new Tree(3);

	root->left->left = new Tree(4);

	if (CheckCollisionPointRec(mousePoint, treeRecs->quitBox))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			binaryGame = false;
		}
	}
}

void BinaryTree::Draw()
{
	BeginDrawing();
	ClearBackground(GRAY);
	DrawRectangleRec(treeRecs->quitBox, BLANK);
	DrawText("QUIT", 700, 400, 20, RED);
	EndDrawing();
}
