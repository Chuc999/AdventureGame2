#include "BinaryTree.h"
#include <queue>


void BinaryTree::init()
{
	screenWidth = 1000.0f;
	screenHeight = 600.0f;

	SetWindowSize((int)screenWidth, (int)screenHeight);
	
	BinaryTree* root = newBranch(39);
	addBranch(root, 10);
	addBranch(root, 45);
	addBranch(root, 5);
	addBranch(root, 40);
	addBranch(root, 8);
	addBranch(root, 15);

	BeginDrawing();
	ClearBackground(BLANK);
	EndDrawing();

	while (binaryGame)
	{
		BinaryTree::update(root);
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

void BinaryTree::update(BinaryTree* root)
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
	if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
	{
		root = deletion(root, 15);
	}
}

void BinaryTree::delBranch(BinaryTree* root, BinaryTree* branch)
{
	queue<class BinaryTree*> q;
	q.push(root);

	BinaryTree* temp;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();

		if (temp == branch)
		{
			temp = NULL;
			delete (branch);
			return;
		}
		if (temp->right)
		{
			if (temp->right == branch)
			{
				temp->right = NULL;
				delete (branch);
				return;
			}
			else
			{
				q.push(temp->right);
			}
		}
		if (temp->left)
		{
			if (temp->left == branch)
			{
				temp->left = NULL;
				delete (branch);
				return;
			}
			else
			{
				q.push(temp->left);
			}
		}

	}
}

BinaryTree* BinaryTree::deletion(BinaryTree* root, int key)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->left == NULL && root->right == NULL)
	{
		if (root->key == key)
		{
			return NULL;
		}
		else
		{
			return root;
		}
	}

	queue<class BinaryTree*> q;
	q.push(root);

	BinaryTree* temp = new BinaryTree();
	BinaryTree* key_node = NULL;

	while (!q.empty())
	{
		temp = q.front();
		q.pop();

		if (temp->key == key)
		{
			key_node = temp;
		}
		if (temp->left)
		{
			q.push(temp->left);
		}
		if (temp->right)
		{
			q.push(temp->right);
		}
	}
	if (key_node != NULL)
	{
		int x = temp->key;
		delBranch(root, temp);
		key_node->key = x;
	}
	return root;
}

void BinaryTree::Draw(BinaryTree* root)
{
	BeginDrawing();
	ClearBackground(BLACK);
	
	//DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color); 
	
	

	//
	//

	//DrawLine(700, 100, 800, 200, RED); // line from right to right->left
	//DrawLine(700, 100, 600, 200, RED); // line from right to right->right

	//DrawLine(800, 200, 735, 300, RED); // line from right->left to right->left->left
	//DrawLine(800, 200, 875, 300, RED); // line from right->left to right->left->right

	//DrawLine(600, 200, 525, 300, RED); // line from right->right to right->right->left
	//DrawLine(600, 200, 665, 300, RED); // line from right->right to right->right->right


	//

	//
	//DrawCircle(600, 200, 25, WHITE); // right->left
	//DrawCircle(800, 200, 25, WHITE); // right->right
	////DrawRectangleRec(treeRecs->rightBranch, RED);

	//
	//
	//
	////DrawRectangleRec(treeRecs->leftBranch, RED);

	//DrawCircle(525, 300, 25, WHITE); // right->left->left
	//DrawCircle(665, 300, 25, WHITE); // right->left->right

	//DrawCircle(735, 300, 25, WHITE); // right->right->left
	//DrawCircle(875, 300, 25, WHITE); // right->right->right
	//
	if (root->key != 0)
	{
		DrawCircle(500, 50, 25, WHITE); // Key
		DrawText(TextFormat("%i", root->key), 485, 35, 30, RED);
	}
	if (root->left != nullptr)
	{
		DrawLine(475, 50, 300, 100, RED); // line from Key to left
		DrawCircle(300, 100, 25, WHITE); // left
		DrawText(TextFormat("%i", root->left->key), 285, 85, 30, RED);
	}
	if (root->right != nullptr)
	{
		DrawLine(525, 50, 700, 100, RED); // line from Key to Right
		DrawCircle(700, 100, 25, WHITE); // right	
		DrawText(TextFormat("%i", root->right->key), 685, 85, 30, RED);
	}
	if (root->left->left != nullptr)
	{
		DrawLine(275, 115, 200, 200, RED); // line from left to left->left
		DrawCircle(200, 200, 25, WHITE); // left->left
		DrawText(TextFormat("%i", root->left->left->key), 185, 185, 30, RED);
	}
	if (root->left->right != nullptr)
	{
		DrawLine(325, 115, 400, 200, RED); // line from left to left->Right
		DrawCircle(400, 200, 25, WHITE); // left->Right
		DrawText(TextFormat("%i", root->left->right->key), 385, 185, 30, RED);
	}

	DrawRectangleRec(treeRecs->quitBox, BLANK);
	DrawText("QUIT", 900, 550, 20, RED);
	EndDrawing();
}
