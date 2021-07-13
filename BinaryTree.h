#pragma once
//#include "include/raylib.h"
//#include <iostream>
#include "Menu.h"

using namespace std;

class BinaryTree : protected Menu
{
protected:
	struct recs
	{
		Rectangle quitBox	{ 900, 550, 50, 20 };
		Rectangle keyBranch	{ 485, 35, 40, 40 };
		Rectangle leftBranch{ 285, 85, 40, 40 };
		Rectangle rightBranch{ 685, 85, 40, 40 };
	};

	int key;
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



	float screenWidth = 800.0f;
	float screenHeight = 600.0f;

	recs* treeRecs = new recs();
	void update();
	void Draw(BinaryTree* root);
	Font font1 = LoadFont("resources/custom_mecha.png");

public:
	bool binaryGame = true;
	void init();

};

