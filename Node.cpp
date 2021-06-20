#include "Node.h"
#include "Menu.h"

void Node::draw(Node* n)
{
	BeginDrawing();	
	ClearBackground(BLACK);

	DrawText("Push", (int)nodeRecs->pushBox.x + 40, (int)nodeRecs->pushBox.y - 20, 20, MAROON);
	DrawRectangleRec(nodeRecs->pushBox, LIGHTGRAY);

	DrawText("End", (int)nodeRecs->appendBox.x + 40, (int)nodeRecs->appendBox.y - 20, 20, MAROON);
	DrawRectangleRec(nodeRecs->appendBox, LIGHTGRAY);

	DrawText("Insert", (int)nodeRecs->insertAfterBox.x + 40, (int)nodeRecs->insertAfterBox.y - 20, 20, MAROON);
	DrawRectangleRec(nodeRecs->insertAfterBox, LIGHTGRAY);

	DrawText("Reverse List", (int)nodeRecs->reverseBox.x + 20, (int)nodeRecs->reverseBox.y - 20, 20, MAROON);
	DrawRectangleRec(nodeRecs->reverseBox, LIGHTGRAY);

	DrawText("Delete End", (int)nodeRecs->deleteBox.x + 20, (int)nodeRecs->deleteBox.y - 20, 20, MAROON);
	DrawRectangleRec(nodeRecs->deleteBox, LIGHTGRAY);
	
	if (n != NULL)
	{
		for (int i = 0; i < 8; i++)
		{
			DrawCircle((165 + (i * 65)), 150, 25, WHITE);
			DrawText((TextFormat("%i", n->data)), (150 + (i * 65)), 130, 40, RED);

			if (n->next != NULL)
			{
				n = n->next;
			}
			else if (n->next == NULL)
			{
				break;
			}
		}
	}

	DrawRectangleRec(nodeRecs->quitBox, BLANK);
	DrawText("QUIT", 700, 400, 20, RED);
	
	EndDrawing();
}

void Node::update()
{
	mousePoint = GetMousePosition();

	if(CheckCollisionPointRec(mousePoint, nodeRecs->appendBox))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			Node::append(&head, 6);
		}
	}

	if (CheckCollisionPointRec(mousePoint, nodeRecs->pushBox))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			Node::push(&head, 7);
		}
	}

	if (CheckCollisionPointRec(mousePoint, nodeRecs->deleteBox))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			Node::reverseList(&head);
		}
	}
	
	if(CheckCollisionPointRec(mousePoint, nodeRecs->quitBox))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			nodeGame = false;
		}
	}
	
}

void Node::init()
{
	BeginDrawing();
	ClearBackground(BLANK);
	EndDrawing();

	mousePoint = { 0.0f,0.0f };
	
	//Node* head = new Node();												// Start with the empty list

	//Node::append(&head, 6);												// Insert 6. So linked list becomes 6->NULL

	//Node::push(&head, 7);												// Insert 7 at the beginning. So linked list becomes 7-> 6-> NULL

	//Node::push(&head, 1);												// Insert 1 at the beginning. So linked list becomes 1-> 7-> 6-> NULL	

	//Node::append(&head, 4);												// Insert 4 at the end. So linked list becomes 1-> 7-> 6-> 4-> NULL

	//Node::insertAfter(head->next, 8);									// Insert 8, after 7. So linked list becomes 1-> 7-> 8-> 6-> 4-> NULL

	//Node::append(&head, 3);

	//Node::push(&head, 10);

	//Node::insertAfter(head->next, 4);

	while (nodeGame)
	{
		Node::update();
		Node::draw(head);		
	}
}

// Given a reference (pointer to pointer) to the head of a list and an int, inserts a new node on the front of the list.
void Node::push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();								// 1. allocate node

	new_node->data = new_data;									// 2. put in the data

	new_node->next = (*head_ref);								// 3. Make next of new node as head
	new_node->prev = NULL;										

	if ((*head_ref) != NULL)									// 4. previous of head is new node
	{
		(*head_ref)->prev = new_node;
	}

	(*head_ref) = new_node;										// 5. move the head to point to the new node
}


// Given a node prev_node, insert a new node after the given prev_node
void Node::insertAfter(Node* prev_node, int new_data)
{
	if (prev_node == NULL)														// 1. Check if the given prev_node is NULL
	{

		cout << " The given previous node connot be NULL" << endl << endl;
		return;
	}

	Node* new_node = new Node();												// 2. Allocate new node

	new_node->data = new_data;													// 3. Put in the data

	new_node->next = prev_node->next;											// 4. Make next of new node as next of prev_node

	prev_node->next = new_node;													// 5. Move the next of prev_node as new_node

	new_node->prev = prev_node;													// 6. now set prev of newnode to prev node

	if (new_node->next != NULL)													// 7. set prev of new node's next to newnode
	{
		new_node->next->prev = new_node;
	}
}

// Given a reference (pointer to pointer) to the head of a list and an int, appends a new node at the end
void Node::append(Node** head_ref, int new_data)
{
	Node* new_node = new Node();												// 1. allocate node

	Node* last = *head_ref;														// Used in step 5

	new_node->data = new_data;													// 2. Put in the data

	new_node->next = NULL;														// 3. This new node is going to be the last node, so make next of it as NULL

	if (*head_ref == NULL)														// 4. If the Linked List is empty, then make the new node as head
	{
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}

	while (last->next != NULL)													// 5. Else traverse till the last node
	{
		last = last->next;
	}

	last->next = new_node;														// 6. Change the next of last node

	new_node->prev = last;
	return;
}

void Node::reverseList(Node** head)
{
	Node* left = *head;
	Node* right = *head;

	if ((*head) == NULL)
	{
		return;
	}
	while (right->next != nullptr)
	{
		right = right->next;
	}

	while (left != right && left->prev != right)
	{
		swap(left->data, right->data);
		left = left->next;
		right = right->prev;
	}
}

void Node::deleteEnd(Node* head, int del_item)
{
	
}

int Node::getHeadData(Node* head)
{	
	return head->data;
}