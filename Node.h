#pragma once
#include "include/raylib.h"

#include <iostream>


using namespace std;

class Node
{
protected:
	struct rects
	{
		Rectangle pushBox		{ 40, 50, 100, 50 };
		Rectangle appendBox		{ 200, 50, 100, 50 };
		Rectangle insertAfterBox{ 360, 50, 100, 50 };
		Rectangle reverseBox	{ 420, 50, 100, 50 };
		Rectangle deleteBox		{ 580, 50, 100, 50 };

		Rectangle quitBox		{ 700, 400, 50, 20 };
	};

	rects* nodeRecs = new rects();

	int valueBoxValue = 0;
	bool valueBoxEditMode = false;
	
	int data;
	int dataPrev;
	Node* next;
	Node* prev;
	Node* current;


	Node* head = NULL;
	void update();
	void draw(Node*);
	void push(Node**, int);
	void insertAfter(Node*, int);
	void append(Node**, int);
	void deleteEnd(Node*, int);
	void reverseList(Node**);
	int getHeadData(Node*);

	Vector2 mousePoint;

public:
	
	bool nodeGame = true;
	void init();
};

