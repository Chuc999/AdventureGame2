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
		Rectangle quitBox{ 700, 400, 50, 20 };
	};

	struct Tree
	{
		int data;

		Tree* left;
		Tree* right;

		Tree(int val)
		{
			data = val;

			// Left and right child for node
			// will be initialized to null
			left = NULL;
			right = NULL;
		}
	};

	recs* treeRecs = new recs();
	void update();
	void Draw();

public:
	bool binaryGame = true;
	void init();

};

