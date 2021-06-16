#include "Node.h"

void Node::draw(Node* n)
{
	BeginDrawing();	
	ClearBackground(GRAY);

	
	if (n != NULL)
	{
		for (int i = 0; i < 8; i++)
		{
			DrawCircle((215 + (i * 65)), 120, 25, BLACK);
			DrawText((TextFormat("%i", n->data)), (200 + (i * 65)), 100, 40, RED);

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
	
	EndDrawing();
}

void Node::update()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		//nodeGame = false;
		//Node::push(&head, 7);
		Node::append(&head, 6);		
	}
	if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
	{
		Node::insertAfter(head->next, 12);
	}
}

void Node::init()
{
	BeginDrawing();
	ClearBackground(BLANK);
	EndDrawing();

	
	//Node* head = new Node();
														// Start with the empty list

	//Node::append(&head, 6);												// Insert 6. So linked list becomes 6->NULL

	//Node::push(&head, 7);												// Insert 7 at the beginning. So linked list becomes 7-> 6-> NULL

	Node::push(&head, 1);												// Insert 1 at the beginning. So linked list becomes 1-> 7-> 6-> NULL	

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

	(*head_ref) = new_node;										// 4. move the head to point to the new node
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
		*head_ref = new_node;
		return;
	}

	while (last->next != NULL)													// 5. Else traverse till the last node
	{
		last = last->next;
	}

	last->next = new_node;														// 6. Change the next of last node
	return;
}