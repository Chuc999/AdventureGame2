#pragma once
#include "include/raylib.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include "NewGame.h"


#define MAX_NAME 50
#define TABLE_SIZE 10
#define PLAYER_NAMES 100


using namespace std;

class Hash
{
public:

	struct Person
	{
		char name[MAX_NAME];
		int age;
		Person* next;
		int loction;
	};

	Person* hash_table[TABLE_SIZE];
	Person n[PLAYER_NAMES];
	unsigned int hash(const char* name);

	int main2();

	void print_table();

	bool hash_table_insert(struct Person* p);

	int list = 0;

	bool displayList = false;
	int display = 0;

	Person* hash_table_lookup(const char* name)
	{
		print_table();
		int index = hash(name);
		Person* temp = hash_table[index];
		while (temp != NULL && strncmp(temp->name, name, MAX_NAME) != 0)
		{
			temp = temp->next;
		}
		if (temp == NULL)
		{
			cout << "\n\t" << name << " Not Found" << endl << endl;
		}
		else
		{
			cout << "\n\tFound\n" << "\t" << temp->name << "\n\tAGE: " << temp->age << " \n\tLocation: " << temp->loction << endl << endl;
		}

		return temp;

	}

	Person* hash_table_delete(const char* name)
	{
		int index = hash(name);
		Person* temp = hash_table[index];
		Person* prev = NULL;
		while (temp != NULL && strncmp(temp->name, name, MAX_NAME) != 0)
		{
			prev = temp;
			temp = temp->next;
		}
		if (temp == NULL)
		{
			print_table();
			cout << "\n\t" << name << " Not Found" << endl << endl;
			return NULL;
		}
		if (prev == NULL)
		{
			hash_table[index] = temp->next;
		}
		else
		{
			prev->next = temp->next;
		}

		print_table();
		cout << "\n\t" << temp->name << " Deleted from " << temp->loction << endl << endl;

		return temp;
	}

	void search();
	void deletePerson();
	void addNames();

public:
	void init();
	void init_hash_table();
};

