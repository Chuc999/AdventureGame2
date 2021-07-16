#include "BinaryTree.h"
#include <queue>


void BinaryTree::init()
{
	screenWidth = 1000.0f;
	screenHeight = 650.0f;

	SetWindowSize((int)screenWidth, (int)screenHeight);
	
	BinaryTree* root = newBranch(25);
	branches[0] = root->key;
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

	if (CheckCollisionPointRec(mousePoint, delRecs->delTwo))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			deleteNode(root, branches[1]);
			branches[1] = 0;
			for (int i = 0; i < 10; i++)
			{
				if (branches[i] == 0)
				{
					branches[i] = branches[i + 1];
					branches[i + 1] = 0;
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
						addBranch(root, i);
						break;
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

void BinaryTree::searchTree(BinaryTree* root, int input)
{
	BinaryTree* temp = root;
	BinaryTree* temp2 = new BinaryTree();
	if (temp == NULL)
	{
		cout << " Number not found" << endl << endl;
		return;
	}
	if (temp->key == input)
	{
		cout << "Found";
		
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


BinaryTree* BinaryTree::deleteNode(BinaryTree* root, int key)
{
	// base case
	if (root == NULL)
		return root;

	// If the key to be deleted is
	// smaller than the root's
	// key, then it lies in left subtree
	if (key < root->key)
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is
	// greater than the root's
	// key, then it lies in right subtree
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	// if key is same as root's key, then This is the node
	// to be deleted
	else {
		// node has no child
		if (root->left == NULL and root->right == NULL)
			return NULL;

		// node with only one child or no child
		else if (root->left == NULL) {
			BinaryTree* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			BinaryTree* temp = root->left;
			free(root);
			return temp;
		}

		// node with two children: Get the inorder successor
		// (smallest in the right subtree)
		BinaryTree* temp = minValueNode(root->right);

		// Copy the inorder successor's content to this node
		root->key = temp->key;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->key);
	}

	return root;
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

	DrawText("Can only delete second one in list on the right but the drawing isnt working for me", 10, 600, 20, RED);

	DrawRectangleRec(treeRecs->inputBox, LIGHTGRAY);
	DrawText("Click to add number", 10, 10, 20, RED);
	DrawRectangleRec(treeRecs->deleteBox, LIGHTGRAY);


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
	Draw2(root, 500, 50, 400, root);
}

void BinaryTree::Draw2(BinaryTree* root, int x, int y, int hozSpacing, BinaryTree* selected)
{
	hozSpacing /= 2;

	if (root)
	{
		if (root->HasLeft())
		{
			DrawLine(x, y, x - hozSpacing, y + 80, RED);

			Draw2(root->GetLeft(), x - hozSpacing, y + 80, hozSpacing, selected);
		}

		if (root->HasRight())
		{
			DrawLine(x, y, x + hozSpacing, y + 80, RED);

			Draw2(root->GetRight(), x + hozSpacing, y + 80, hozSpacing, selected);
		}

		root->Draw3(x, y, (selected == root));
	}
}

void BinaryTree::Draw3(int x, int y, bool selected)
{
	static char buffer[10];

	sprintf_s(buffer, "%d", key);

	DrawCircle(x, y, 28, YELLOW);

	if (selected == true)
	{
		DrawCircle(x, y, 28, GREEN);
	}
	else
	{
		DrawCircle(x, y, 28, GREEN);
	}

	DrawText(buffer, x - 12, y - 10, 25, WHITE);

}

void BinaryTree::DrawFull()
{
	DrawText("Tree Full", 50, 90, 20, RED);
}