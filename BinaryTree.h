#pragma once
//#include "include/raylib.h"
//#include <iostream>
#include "Menu.h"
#include <string>
#define MAX_INPUT_CHARS     3
using namespace std;

class BinaryTree : protected Menu
{
private:
	
protected:
	
	struct recs
	{
		Rectangle quitBox	{ 800, 550, 50, 20 };
		Rectangle inputBox	{ 50, 30, 100, 50 };
		Rectangle SearchBox	{ 50, 60, 25, 25 };
		Rectangle deleteBox	{ 50, 120, 100, 50 };

		Rectangle keyBranch	{ 485, 35, 40, 40 };
		Rectangle leftBranch{ 285, 85, 40, 40 };
		Rectangle rightBranch{ 685, 85, 40, 40 };

		Rectangle brachArray{ 900, 50, 50, 50 };
	};

	struct deleteBoxes
	{
		Rectangle delOne	{ 900, 20, 40, 40 };
		Rectangle delTwo	{ 900, 85, 40, 40 };
		Rectangle delThree	{ 900, 150, 40, 40 };
		Rectangle delFour	{ 900, 215, 40, 40 };
		Rectangle delFive	{ 900, 280, 40, 40 };
		Rectangle delSix	{ 900, 345, 40, 40 };
		Rectangle delSeven	{ 900, 410, 40, 40 };
		Rectangle delEight	{ 900, 475, 40, 40 };
		Rectangle delNine	{ 900, 540, 40, 40 };
		Rectangle delTen	{ 900, 605, 40, 40 };
	};

	

	int key = 0;
	BinaryTree* left = NULL;
	BinaryTree* right = NULL;

	BinaryTree* newBranch(int value)
	{
		BinaryTree* temp = new BinaryTree();
		temp->key = value;
		temp->left = temp->right = NULL;
		return temp;
	}

	void addBranch(BinaryTree* root, int input);
	void addTreeRight(BinaryTree* right, int input);
	void addTreeLeft(BinaryTree* left, int input);

	int branches[10];
	

	BinaryTree* deleteNode(BinaryTree* root, int input);
	BinaryTree* minValueNode(BinaryTree* node);

	float screenWidth = 800.0f;
	float screenHeight = 600.0f;

	recs* treeRecs = new recs();
	deleteBoxes* delRecs = new deleteBoxes();

	void update(BinaryTree* root);
	void Draw();
	void DrawTest(BinaryTree* root);
	BinaryTree* searchTree(BinaryTree* root, int input);
	void Draw2(BinaryTree* pNode, int x, int y, int hozSpacing);
	void Draw3(int x, int y);
	void DrawFull();
public:
	bool binaryGame = true;
	void init();

	bool HasLeft()
	{
		return (left != nullptr);
	}
	bool HasRight()
	{
		return (right != nullptr);
	}

	int GetData()
	{
		return key;
	}
	BinaryTree* GetLeft()
	{
		return left;
	}
	BinaryTree* GetRight()
	{
		return right;
	}
};

