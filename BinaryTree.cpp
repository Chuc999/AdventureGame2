#include "BinaryTree.h"
#include <queue>


void BinaryTree::init()
{
	screenWidth = 1000.0f;
	screenHeight = 650.0f;

	SetWindowSize((int)screenWidth, (int)screenHeight);
	
	BinaryTree* root = new BinaryTree();

	BeginDrawing();
	ClearBackground(BLANK);
	EndDrawing();

	while (binaryGame)
	{
		BinaryTree::update(root);
		BeginDrawing();
		BinaryTree::DrawTest(root);
		BinaryTree::Draw();
		EndDrawing();
	}
}

void BinaryTree::addBranch(BinaryTree* root, int input)
{
	BinaryTree* temp = root;
	BinaryTree* temp2 = new BinaryTree();
	BinaryTree* temp3 = new BinaryTree();

	
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

	if (CheckCollisionPointRec(mousePoint, delRecs->delOne))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			BinaryTree* temp = root;
			root = deleteNode(temp, branches[0]);
			ClearBackground(BLANK);
			DrawTest(root);
			branches[0] = 0;
			for (int i = 0; i < 10; i++)
			{
				if (branches[i] == 0)
				{
					branches[i] = branches[i + 1];
					branches[i + 1] = 0;
					branches[9] = 0;
				}
			}
		}
	}

	if (CheckCollisionPointRec(mousePoint, delRecs->delTwo))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{			
			root = deleteNode(root, branches[1]);
			ClearBackground(BLANK);
			DrawTest(root);
			branches[1] = 0;
			for (int i = 0; i < 10; i++)
			{
				if (branches[i] == 0)
				{
					branches[i] = branches[i + 1];
					branches[i + 1] = 0;
					branches[9] = 0;
				}
			}
		}
	}

	if (CheckCollisionPointRec(mousePoint, treeRecs->inputBox))
	{
		if (branches[9] == NULL)
		{
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			{
				int i = GetRandomValue(1, 50);
				
				for (int j = 0; j < 10; j++)
				{
					if (branches[j] == i)
					{
						break;
					}
					if (branches[j] == 0)
					{
						branches[j] = i;
						if (root->key == NULL)
						{
							root->key = i;
							break;
						}
						else
						{
							addBranch(root, i);
							break;
						}
					}					
				}				
			}
		}
		else
		{
			DrawFull();
		}
	}	
}

BinaryTree* BinaryTree::searchTree(BinaryTree* root, int input)
{
	BinaryTree* temp = root;
	BinaryTree* temp2 = new BinaryTree();
	if (temp == NULL)
	{
		cout << " Number not found" << endl << endl;
		return NULL;
	}
	if (temp->key == input)
	{
		root = deleteNode(root, key);
		return root;
		
	}
	else if (input > temp->key)
	{
		temp2 = temp->right;
		searchTree(temp2, input);
	}
	else
	{
		temp2 = temp->left;
		searchTree(temp2, input);
	}
}


BinaryTree* BinaryTree::deleteNode(BinaryTree* test, int key)
{
	// base case
	if (test == NULL)
		return test;

	// If the key to be deleted is
	// smaller than the root's
	// key, then it lies in left subtree
	if (key < test->key)
		test->left = deleteNode(test->left, key);

	// If the key to be deleted is
	// greater than the root's
	// key, then it lies in right subtree
	else if (key > test->key)
		test->right = deleteNode(test->right, key);

	// if key is same as root's key, then This is the node
	// to be deleted
	else 
	{
		// node has no child
		if (test->left == NULL and test->right == NULL)
			return NULL;

		// node with only one child or no child
		else if (test->left == NULL) {
			BinaryTree* temp = test->right;
			free(test);
			return temp;
		}
		else if (test->right == NULL) {
			BinaryTree* temp = test->left;
			free(test);
			return temp;
		}

		// node with two children: Get the inorder successor
		// (smallest in the right subtree)
		BinaryTree* temp = minValueNode(test->right);

		// Copy the inorder successor's content to this node
		test->key = temp->key;

		// Delete the inorder successor
		test->right = deleteNode(test->right, temp->key);
	}

	return test;
}

BinaryTree* BinaryTree::minValueNode(BinaryTree* node)
{
	BinaryTree* current = node;

	/* loop down to find the leftmost leaf */
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

void BinaryTree::Draw()
{
	DrawRectangleRec(treeRecs->inputBox, LIGHTGRAY);
	DrawText("Click to add number", 10, 10, 20, RED);

	for (int i = 0; i < 10; i++)
	{
		DrawRectangle(900, 20 + (i * 65), 40, 40, WHITE);
		DrawText((TextFormat("%i", branches[i])), 903, 20 + (i * 65), 30, RED);
	}
	DrawRectangleRec(treeRecs->quitBox, BLANK);
	DrawText("QUIT", 800, 550, 20, RED);
}

void BinaryTree::DrawTest(BinaryTree* root)
{	
	ClearBackground(BLANK);
	Draw2(root, 500, 50, 400);
}

void BinaryTree::Draw2(BinaryTree* root, int x, int y, int hozSpacing)
{
	hozSpacing /= 2;

	if (root)
	{
		if (root->HasLeft())
		{
			DrawLine(x, y, x - hozSpacing, y + 80, RED);

			Draw2(root->GetLeft(), x - hozSpacing, y + 80, hozSpacing);
		}

		if (root->HasRight())
		{
			DrawLine(x, y, x + hozSpacing, y + 80, RED);

			Draw2(root->GetRight(), x + hozSpacing, y + 80, hozSpacing);
		}

		root->Draw3(x, y);
	}
}

void BinaryTree::Draw3(int x, int y)
{
	static char buffer[10];

	sprintf_s(buffer, "%d", key);

	DrawCircle(x, y, 28, YELLOW);

	DrawCircle(x, y, 28, GREEN);

	DrawText(buffer, x - 12, y - 10, 25, WHITE);

}

void BinaryTree::DrawFull()
{
	DrawText("Tree Full", 50, 90, 20, RED);
}