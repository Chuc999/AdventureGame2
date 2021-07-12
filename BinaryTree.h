#pragma once
#include "include/raylib.h"
#include <iostream>

using namespace std;

class BinaryTree
{
protected:

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
	
public:
	void init();
	void update();
	void Draw();
};

