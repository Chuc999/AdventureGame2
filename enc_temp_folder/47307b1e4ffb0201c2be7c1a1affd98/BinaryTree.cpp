#include "BinaryTree.h"


void BinaryTree::init()
{
	screenWidth = 1000.0f;
	screenHeight = 600.0f;

	SetWindowSize((int)screenWidth, (int)screenHeight);
	
	BinaryTree* root = newBranch(39);
	addBranch(root, 10);
	addBranch(root, 45);

	BeginDrawing();
	ClearBackground(BLANK);
	EndDrawing();

	while (binaryGame)
	{
		BinaryTree::update();
		BinaryTree::Draw(root);
	}
}

void BinaryTree::addBranch(BinaryTree* root, int input)
{
	BinaryTree* temp = root;
	BinaryTree* temp2 = new BinaryTree();
	BinaryTree* temp3 = new BinaryTree();

	if (temp->key == NULL)
	{
		temp = newBranch(input);
	}
	if (input > temp->key)
	{
		if (temp->right != nullptr)
		{
			temp3 = temp->right;
			addTreeRight(temp3, input);
		}
		else
		{
			temp->right = newBranch(input);
		}
	}
	else
	{
		if (temp->left != nullptr)
		{
			temp2 = temp->left;
			addTreeLeft(temp2, input);
		}
		else
		{
			temp->left = newBranch(input);
		}
	}
}

void BinaryTree::addTreeRight(BinaryTree* right, int input)
{
	BinaryTree* temp = right;
	BinaryTree* temp2 = new BinaryTree();
	if (input > temp->key)
	{
		if (temp->right != nullptr)
		{
			temp2 = temp->right;
			addBranch(temp2, input);
		}
		else
		{
			temp->right = newBranch(input);
		}
	}
	else
	{
		addBranch(right, input);
	}
}

void BinaryTree::addTreeLeft(BinaryTree* left, int input)
{
	BinaryTree* temp = left;
	BinaryTree* temp2 = new BinaryTree();
	if (input < temp->key)
	{
		if (temp->left != nullptr)
		{
			temp2 = temp->left;
			addBranch(temp2, input);
		}
		else
		{
			temp->left = newBranch(input);
		}
	}
	else
	{
		addBranch(left, input);
	}
}

void BinaryTree::update()
{
	
	mousePoint = GetMousePosition();
	if (CheckCollisionPointRec(mousePoint, treeRecs->quitBox))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			binaryGame = false;
			SetWindowSize((int)Menu::screenWidth, (int)Menu::screenHeight);
		}
	}
}

void BinaryTree::Draw(BinaryTree* root)
{
	BeginDrawing();
	ClearBackground(BLACK);
	
	//DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color); 
	DrawLine(500, 50, 300, 100, RED); // line from Key to left
	DrawLine(500, 50, 700, 100, RED); // line from Key to Right

	DrawLine(300, 100, 200, 200, RED); // line from left to left->left
	DrawLine(300, 100, 400, 200, RED); // line from left to left->Right

	DrawLine(700, 100, 800, 200, RED); // line from right to right->left
	DrawLine(700, 100, 600, 200, RED); // line from right to right->right

	DrawLine(800, 200, 735, 300, RED); // line from right->left to right->left->left
	DrawLine(800, 200, 875, 300, RED); // line from right->left to right->left->right

	DrawLine(600, 200, 525, 300, RED); // line from right->right to right->right->left
	DrawLine(600, 200, 665, 300, RED); // line from right->right to right->right->right


	DrawCircle(500, 50, 25, WHITE); // Key
	DrawTextRec(font1,(TextFormat("%1", root->key)), treeRecs->keyBranch, 30, 2, true, RED);
	//DrawRectangleRec(treeRecs->keyBranch, RED);

	DrawCircle(700, 100, 25, WHITE); // right
	DrawTextRec(font1, (TextFormat("%1", root->right)), treeRecs->rightBranch, 30, 2, false, RED);
	DrawCircle(600, 200, 25, WHITE); // right->left
	DrawCircle(800, 200, 25, WHITE); // right->right
	//DrawRectangleRec(treeRecs->rightBranch, RED);

	DrawCircle(300, 100, 25, WHITE); // left
	DrawTextRec(font1, (TextFormat("%i", root->left)), treeRecs->leftBranch, 30, 2, true, RED);
	DrawCircle(200, 200, 25, WHITE); // left->left
	DrawCircle(400, 200, 25, WHITE); // left->Right
	//DrawRectangleRec(treeRecs->leftBranch, RED);

	DrawCircle(525, 300, 25, WHITE); // right->left->left
	DrawCircle(665, 300, 25, WHITE); // right->left->right

	DrawCircle(735, 300, 25, WHITE); // right->right->left
	DrawCircle(875, 300, 25, WHITE); // right->right->right


	DrawRectangleRec(treeRecs->quitBox, BLANK);
	DrawText("QUIT", 900, 550, 20, RED);
	EndDrawing();
}
