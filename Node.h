#pragma once
#include "include/raylib.h"

#include <iostream>


using namespace std;

class Node
{
protected:
	struct rects
	{
		Rectangle pushBox		{ 40, 50, 150, 50 };
		Rectangle appendBox		{ 200, 50, 150, 50 };
		Rectangle insertAfterBox{ 360, 50, 150, 50 };
		Rectangle deleteBox		{ 520, 50, 150, 50 };

		Rectangle quitBox		{ 700, 400, 50, 20 };
	};

	rects* nodeRecs = new rects();

	int valueBoxValue = 0;
	bool valueBoxEditMode = false;
	
	int data;
	Node* next;

	Node* head = NULL;
	void update();
	void draw(Node*);
	void push(Node**, int);
	void insertAfter(Node*, int);
	void append(Node**, int);
	void deleteEnd(Node*);

	Vector2 mousePoint;

public:
	
	bool nodeGame = true;
	void init();
};

