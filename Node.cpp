#include "Node.h"
#include "Menu.h"

void Node::draw(Node* n, int j)
{
	BeginDrawing();	
	ClearBackground(BLACK);

	DrawText("Push", (int)nodeRecs->pushBox.x + 20, (int)nodeRecs->pushBox.y - 20, 20, MAROON);
	if (CheckCollisionPointRec(mousePoint, nodeRecs->pushBox))
	{
		DrawRectangleRec(nodeRecs->pushBox, RED);
	}
	else
	{
		DrawRectangleRec(nodeRecs->pushBox, LIGHTGRAY);
	}

	DrawText("End", (int)nodeRecs->appendBox.x + 20, (int)nodeRecs->appendBox.y - 20, 20, MAROON);
	if (CheckCollisionPointRec(mousePoint, nodeRecs->appendBox))
	{
		DrawRectangleRec(nodeRecs->appendBox, RED);
	}
	else
	{
		DrawRectangleRec(nodeRecs->appendBox, LIGHTGRAY);
	}

	DrawText("Sort", (int)nodeRecs->sortBox.x + 20, (int)nodeRecs->sortBox.y - 20, 20, MAROON);
	if (CheckCollisionPointRec(mousePoint, nodeRecs->sortBox))
	{
		DrawRectangleRec(nodeRecs->sortBox, RED);
	}
	else
	{
		DrawRectangleRec(nodeRecs->sortBox, LIGHTGRAY);
	}

	DrawText("Reverse", (int)nodeRecs->reverseBox.x, (int)nodeRecs->reverseBox.y - 20, 20, MAROON);
	if (CheckCollisionPointRec(mousePoint, nodeRecs->reverseBox))
	{
		DrawRectangleRec(nodeRecs->reverseBox, RED);
	}
	else
	{
		DrawRectangleRec(nodeRecs->reverseBox, LIGHTGRAY);
	}

	DrawText("Del First", (int)nodeRecs->deleteBox.x, (int)nodeRecs->deleteBox.y - 20, 20, MAROON);
	if (CheckCollisionPointRec(mousePoint, nodeRecs->deleteBox))
	{
		DrawRectangleRec(nodeRecs->deleteBox, RED);
	}
	else
	{
		DrawRectangleRec(nodeRecs->deleteBox, LIGHTGRAY);
	}

	DrawText("Del End", (int)nodeRecs->deleteBox2.x + 10, (int)nodeRecs->deleteBox2.y - 20, 20, MAROON);
	if (CheckCollisionPointRec(mousePoint, nodeRecs->deleteBox2))
	{
		DrawRectangleRec(nodeRecs->deleteBox2, RED);
	}
	else
	{
		DrawRectangleRec(nodeRecs->deleteBox2, LIGHTGRAY);
	}
	
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
	// Shows Rectangles used for deleting node that is clicked on. Used for debugging

	/*DrawRectangleRec(testRecs->listOne, BLUE);			
	DrawRectangleRec(testRecs->listTwo, BLUE);
	DrawRectangleRec(testRecs->listThree, BLUE);
	DrawRectangleRec(testRecs->listFour, BLUE);
	DrawRectangleRec(testRecs->listFive, BLUE);
	DrawRectangleRec(testRecs->listSix, BLUE);
	DrawRectangleRec(testRecs->listSeven, BLUE);
	DrawRectangleRec(testRecs->listEight, BLUE);*/

	if (j > 7)
	{
		DrawText("List is Full", 360, 400, 10, RED);
	}
	if (j == 0)
	{
		DrawText("List is Empty", 360, 400, 10, RED);
	}

	DrawText("Left Click on node to delete", 250, 250, 20, RED);
	DrawText("Right Click on node to insert on the right", 250, 270, 20, RED);
	DrawText("Middle Click on node to insert on the left", 250, 290, 20, RED);

	DrawText("Number of Nodes - ", 10, 400, 10, RED);
	DrawText((TextFormat("%i", j)), 110, 400, 10, RED);

	if (head != NULL)
	{
		DrawText("First Nod - ", 130, 400, 10, RED);
		int f = getHeadData(head,0);
		DrawText((TextFormat("%i", f)), 195, 400, 10, RED);

		DrawText("Last Nod - ", 220, 400, 10, RED);
		int l = getHeadData(head, 1);
		DrawText((TextFormat("%i", l)), 280, 400, 10, RED);
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
			int j = countNodes(head);
			if (j > 7)
			{
				return;
			}
			else
			{
			int i = GetRandomValue(1, 50);
			Node::append(&head, i);
			}
		}
	}

	if (CheckCollisionPointRec(mousePoint, nodeRecs->pushBox))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			int j = countNodes(head);
			if (j > 7)
			{
				return;
			}
			else
			{
			int i = GetRandomValue(1, 50);
			Node::push(&head, i);
			}
		}
	}

	if (CheckCollisionPointRec(mousePoint, nodeRecs->sortBox))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (head == NULL)
			{
				return;
			}
			else
			{			
			Node::sort(head);
			}
		}
	}

	if (CheckCollisionPointRec(mousePoint, nodeRecs->reverseBox))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			Node::reverseList(&head);
		}
	}

	if (CheckCollisionPointRec(mousePoint, nodeRecs->deleteBox))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (head == NULL)
			{
				return;
			}
			else
			{
				Node::deleteEnd(&head, 1);
			}

		}
	}

	if (CheckCollisionPointRec(mousePoint, nodeRecs->deleteBox2))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (head == NULL)
			{
				return;
			}
			else
			{
			Node::deleteEnd(&head, 0);
			}

		}
	}
	
	if (CheckCollisionPointRec(mousePoint, testRecs->listOne))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (head == NULL)
			{
				return;
			}
			else
			{
				Node::oldDelete(&head, 1);
			}
		}
		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
		{
			int j = countNodes(head);
			if (j > 7)
			{
				return;
			}
			else if (head == NULL)
			{
				return;
			}
			else
			{
				int i = GetRandomValue(1, 50);
				Node::insertAfter(head, i);
			}
		}
		if (IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON))
		{
			int j = countNodes(head);
			if (j > 7)
			{
				return;
			}
			else if (head == NULL)
			{
				return;
			}
			else
			{
				int i = GetRandomValue(1, 50);
				Node::push(&head, i);
			}
		}
	}

	if (CheckCollisionPointRec(mousePoint, testRecs->listTwo))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (head == NULL)
			{
				return;
			}
			else
			{
				Node::oldDelete(&head, 2);
			}
		}
		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
		{
			int j = countNodes(head);
			if (j > 7)
			{
				return;
			}
			else if (head == NULL || head->next == NULL)
			{
				return;
			}
			else
			{
				int i = GetRandomValue(1, 50);
				Node::insertAfter(head->next, i);
			}
		}
		if (IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON))
		{
			int j = countNodes(head);
			if (j > 7)
			{
				return;
			}
			else if (head == NULL || head->next == NULL)
			{
				return;
			}
			else
			{
				int i = GetRandomValue(1, 50);
				Node::insertAfter(head, i);
			}
		}
	}

	if (CheckCollisionPointRec(mousePoint, testRecs->listThree))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (head == NULL)
			{
				return;
			}
			else
			{
				Node::oldDelete(&head, 3);
			}
		}
		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
		{
			int j = countNodes(head);
			if (j > 7)
			{
				return;
			}
			else if (head == NULL || head->next->next == NULL)
			{
				return;
			}
			else
			{
				int i = GetRandomValue(1, 50);
				Node::insertAfter(head->next->next, i);
			}
		}
		if (IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON))
		{
			int j = countNodes(head);
			if (j > 7)
			{
				return;
			}
			else if (head == NULL || head->next->next == NULL)
			{
				return;
			}
			else
			{
				int i = GetRandomValue(1, 50);
				Node::insertAfter(head->next, i);
			}
		}
	}

	if (CheckCollisionPointRec(mousePoint, testRecs->listFour))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (head == NULL)
			{
				return;
			}
			else
			{
				Node::oldDelete(&head, 4);
			}
		}
		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
		{
			int j = countNodes(head);
			if (j > 7)
			{
				return;
			}
			else if (head == NULL || head->next->next->next == NULL)
			{
				return;
			}
			else
			{
				int i = GetRandomValue(1, 50);
				Node::insertAfter(head->next->next->next, i);
			}
		}
		if (IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON))
		{
			int j = countNodes(head);
			if (j > 7)
			{
				return;
			}
			else if (head == NULL || head->next->next->next == NULL)
			{
				return;
			}
			else
			{
				int i = GetRandomValue(1, 50);
				Node::insertAfter(head->next->next, i);
			}
		}
	}

	if (CheckCollisionPointRec(mousePoint, testRecs->listFive))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (head == NULL)
			{
				return;
			}
			else
			{
				Node::oldDelete(&head, 5);
			}
		}
		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
		{
			int j = countNodes(head);
			if (j > 7)
			{
				return;
			}
			else if (head == NULL || head->next->next->next->next == NULL)
			{
				return;
			}
			else
			{
				int i = GetRandomValue(1, 50);
				Node::insertAfter(head->next->next->next->next, i);
			}
		}
		if (IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON))
		{
			int j = countNodes(head);
			if (j > 7)
			{
				return;
			}
			else if (head == NULL || head->next->next->next->next == NULL)
			{
				return;
			}
			else
			{
				int i = GetRandomValue(1, 50);
				Node::insertAfter(head->next->next->next, i);
			}
		}
	}

	if (CheckCollisionPointRec(mousePoint, testRecs->listSix))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (head == NULL)
			{
				return;
			}
			else
			{
				Node::oldDelete(&head, 6);
			}
		}
		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
		{
			int j = countNodes(head);
			if (j > 7)
			{
				return;
			}
			else if (head == NULL || head->next->next->next->next->next == NULL)
			{
				return;
			}
			else
			{
				int i = GetRandomValue(1, 50);
				Node::insertAfter(head->next->next->next->next->next, i);
			}
		}
		if (IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON))
		{
			int j = countNodes(head);
			if (j > 7)
			{
				return;
			}
			else if (head == NULL || head->next->next->next->next->next == NULL)
			{
				return;
			}
			else
			{
				int i = GetRandomValue(1, 50);
				Node::insertAfter(head->next->next->next->next, i);
			}
		}
	}

	if (CheckCollisionPointRec(mousePoint, testRecs->listSeven))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (head == NULL)
			{
				return;
			}
			else
			{
				Node::oldDelete(&head, 7);
			}
		}
		if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
		{
			int j = countNodes(head);
			if (j > 7)
			{
				return;
			}
			else if (head == NULL || head->next->next->next->next->next->next == NULL)
			{
				return;
			}
			else
			{
				int i = GetRandomValue(1, 50);
				Node::insertAfter(head->next->next->next->next->next->next, i);
			}
		}
		if (IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON))
		{
			int j = countNodes(head);
			if (j > 7)
			{
				return;
			}
			else if (head == NULL || head->next->next->next->next->next->next == NULL)
			{
				return;
			}
			else
			{
				int i = GetRandomValue(1, 50);
				Node::insertAfter(head->next->next->next->next->next, i);
			}
		}
	}

	if (CheckCollisionPointRec(mousePoint, testRecs->listEight))
	{
		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			if (head == NULL)
			{
				return;
			}
			else
			{
				Node::oldDelete(&head, 8);
			}
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

	while (nodeGame)
	{
		Node::update();		
		int i = countNodes(head);
		Node::draw(head, i);	

	}
}

int Node::countNodes(Node* head)
{
	Node* temp = head;
	int i = 0;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return i;
}

void Node::sort(Node* head)
{
	int swapped;

	Node* temp1;
	Node* temp2 = NULL;

	if (head == NULL)
	{
		return;
	}

	do
	{
		swapped = 0;
		temp1 = head;

		while (temp1->next != temp2)
		{
			if (temp1->data > temp1->next->data)
			{
				swap(temp1->data, temp1->next->data);
				swapped = 1;
			}
			temp1 = temp1->next;
		}
		temp2 = temp1;
	} 	while (swapped);
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

// Function to reverse the order of the list. I found out how to do this by accident then made the code better so it was more efficent than i had it
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
// Orignal delete function i wrote before i thought of a better way using my reverse function
// i found a use for it. Probably not the best code to use but it works
void Node::oldDelete(Node** head, int i)
{
	Node* del_item = *head;

	switch (i)
	{
	case 0:
		del_item = NULL;
		break;
	case 1:
		del_item = *head;
		break;
	case 2:
		del_item = del_item->next;
		break;
	case 3:
		del_item = del_item->next->next;
		break;
	case 4:
		del_item = del_item->next->next->next;
		break;
	case 5:
		del_item = del_item->next->next->next->next;
		break;
	case 6:
		del_item = del_item->next->next->next->next->next;
		break;
	case 7:
		del_item = del_item->next->next->next->next->next->next;
		break;
	case 8:
		del_item = del_item->next->next->next->next->next->next->next;
		break;
	}

	if (*head == NULL || del_item == NULL)
	{
		return;
	}

	if (*head == del_item)
	{
		*head = del_item->next;
	}

	if (del_item->next != NULL)
	{
		del_item->next->prev = del_item->prev;
	}

	if (del_item->prev != NULL)
	{
		del_item->prev->next = del_item->next;
	}

	free(del_item);
	return;
}

// deletes either first or last node from reffence n. 
// What the code does is delete the head, for it to delete the last node it reverses the list, deletes the head then reverves the list back. 
// This will remove the last node in the list. Again probably not the best way to do it but it works.

void Node::deleteEnd(Node** head, int n)
{
	if (n != 1)
	{
		reverseList(head);
	}	

	Node* del_item = *head;

	if (*head == NULL || del_item == NULL)
	{
		return;
	}

	if (*head == del_item)
	{
		*head = del_item->next;
	}

	if (del_item->next != NULL)
	{
		del_item->next->prev = del_item->prev;
	}

	if (del_item->prev != NULL)
	{
		del_item->prev->next = del_item->next;
	}

	free(del_item);
	if (n != 1)
	{
		reverseList(head);
	}
	return;
}


int Node::getHeadData(Node* head, int n)
{	
	if (n != 1)
	{
		return head->data;
	}
	else
	{
		reverseList(&head);
		int i = head->data;
		reverseList(&head);
		return i;
	}
}