#include "BinaryTree.h"
#include "Menu.h"

void BinaryTree::init()
{
	BeginDrawing();
	ClearBackground(BLANK);
	EndDrawing();
}

void BinaryTree::update()
{
	Tree* root = new Tree(1);

	root->left = new Tree(2);
	root->right = new Tree(3);

	root->left->left = new Tree(4);
}

void BinaryTree::Draw()
{

}
