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
		Rectangle appendBox		{ 160, 50, 100, 50 };
		Rectangle sortBox		{ 280, 50, 100, 50 };
		Rectangle reverseBox	{ 400, 50, 100, 50 };
		Rectangle deleteBox		{ 520, 50, 100, 50 };
		Rectangle deleteBox2	{ 640, 50, 100, 50 };
		Rectangle quitBox		{ 700, 400, 50, 20 };
	};

	struct recTest
	{
		Rectangle listOne		{ 145, 130, 40, 40 };
		Rectangle listTwo		{ 210, 130, 40, 40 };
		Rectangle listThree		{ 275, 130, 40, 40 };
		Rectangle listFour		{ 340, 130, 40, 40 };
		Rectangle listFive		{ 405, 130, 40, 40 };
		Rectangle listSix		{ 470, 130, 40, 40 };
		Rectangle listSeven		{ 535, 130, 40, 40 };
		Rectangle listEight		{ 600, 130, 40, 40 };
	};

	rects* nodeRecs = new rects();
	recTest* testRecs = new recTest();

	int valueBoxValue = 0;
	bool valueBoxEditMode = false;
	
	int data = 0;
	Node* next = NULL;
	Node* prev = NULL;

	Node* head = NULL;
	int countNodes(Node*);
	void update();
	void draw(Node*,int);
	void push(Node**, int);
	void insertAfter(Node*, int);
	void append(Node**, int);
	void deleteEnd(Node**,int);
	void reverseList(Node**);
	int getHeadData(Node*, int);
	void sort(Node*);

	Vector2 mousePoint = { 0.0f,0.0f };

	void oldDelete(Node**, int);

public:
	
	bool nodeGame = true;
	void init();
};

