#include "Hash.h"

int Hash::main2()
{


	system("cls");

	Hash* test = new Hash();
	cout << endl << "\t\t\tWelcome to my hash table\n\tYou will be able to add, search and delete names from the table" << endl << endl;
	system("pause");
	test->init_hash_table();
	test->init();
	return 0;
}

void Hash::init()
{

	system("cls");
	print_table();

	cout << endl;
	string options[5] = { "[1] Add Names", "[2] Search Names", "[3] Delete Names", "[4] Show/Hide Hash Table", "[5] Quit" };

	for (int i = 0; i < 5; i++)
	{
		cout << "\t" << options[i] << endl;
	}

	int i;
	cin >> i;
	switch (i)
	{
	case 1:
		system("cls");
		addNames();
		print_table();
		init();
		break;
	case 2:
		search();
		break;
	case 3:
		deletePerson();
		break;
	case 4:
		if (display == 0)
		{
			displayList = true;
			display++;
		}
		else
		{
			displayList = false;
			display--;
		}
		init();
		break;
	case 5:
		//exit(0);
		NewGame * testGame = new NewGame();
		testGame->newGame = true;
		break;
	}
}

void Hash::addNames()
{
	print_table();
	cout << "Add Person" << endl << "Insert Name" << endl << endl;
	char k[MAX_NAME];
	cin >> k;
	int length = strlen(k);
	for (int i = 0; i < length; i++)
	{
		n[list].name[i] = k[i];
	}
	int j = 0;
	cout << "Insert Age" << endl << endl;
	cin >> j;
	n[list].age = j;
	hash_table_insert(&n[list]);
	list++;
	system("cls");

	init();
}

void Hash::deletePerson()
{
	cout << " Delete Person" << endl;
	char k[MAX_NAME];
	cin >> k;
	system("cls");
	hash_table_delete(k);
	system("pause");
	init();
}

void Hash::search()
{
	cout << " Search for" << endl;
	char k[MAX_NAME];
	cin >> k;
	system("cls");
	Person* temp = hash_table_lookup(k);
	system("pause");
	init();
}

void Hash::print_table()
{
	if (displayList)
	{

		cout << "\tHash Table" << endl;
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			if (hash_table[i] == NULL)
			{
				cout << "\t" << i << " => " << "---" << endl;
			}
			else
			{
				cout << "\t" << i;
				Person* temp = hash_table[i];
				temp->loction = i;
				while (temp != NULL)
				{
					cout << " => " << temp->name;
					temp = temp->next;
				}
				cout << endl;
			}

		}
	}
}

bool Hash::hash_table_insert(struct Person* p)
{
	if (p == NULL) return false;
	int index = hash(p->name);
	p->next = hash_table[index];
	hash_table[index] = p;
	return true;
}

unsigned int Hash::hash(const char* name)
{
	int length = strlen(name);
	unsigned int hash_value = 0;
	for (unsigned int i = 0; i < length; i++)
	{
		hash_value += name[i];
		hash_value = (hash_value * name[i]) % TABLE_SIZE;
	}
	return hash_value;
}

void Hash::init_hash_table()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		hash_table[i] = NULL;
	}
}


