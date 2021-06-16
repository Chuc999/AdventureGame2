#pragma once
#include "include/raylib.h"

#include <iostream>


using namespace std;

class Node
{
protected:
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

public:
	
	bool nodeGame = true;
	void init();
};

