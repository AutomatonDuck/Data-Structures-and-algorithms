// Single_linked_lists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class nlinklist {  // node definition
public:

	int data;
	class nlinklist* next;
};

typedef class nlinklist node;
node* start = NULL;

//new node function
node* getnode()
{
	node* mylist = new node[sizeof(node)];	// can also use c syntax: mylist = (node*)malloc(sizeof(node));
	cout << "Enter data:	";
	cin >> mylist->data;
	mylist->next = NULL;
	return mylist;

}

//creates new nodes, # defined by user
void create(int n)
{
	int i;
	node* temp, *mylist;
	for (i = 0; i < n; i++)
	{
		mylist = getnode();
		if (start == NULL)
		{
			start = mylist;
		}
		else
		{
			temp = start;
			while (temp->next != NULL)
			{
				temp = temp->next;
				
			}
			temp->next = mylist;
		}
	}

}

//will traverse and read list
void read()
{
	node* temp;
	temp = start;

	cout << "Will read list from left to right" << endl;

	if (start == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	while (temp->next != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
	cout << temp->data << endl; // loop doesnt display last element
	
}

int node_count()
{
	node* temp;
	int count = 1; // accounting for while loop not counting last node
	temp = start;
	if (start == NULL)
	{
		cout << "List is empty" << endl;
		return 0;
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
		count++;
	}
	return count;
}


void delete_from_mid()
{
	int ctr = 1, pos, nodectr;
	node* temp, * prev;
	if (start == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	cout << "Enter position to be deleted:	";
	cin >> pos;
	nodectr = node_count();
	/*cout << nodectr;*/ // test line
	if (pos < ctr)
	{
		cout << "Position error" << endl;
		return;
	}
	if (pos > 1 && pos < nodectr)
	{
		temp = start;
		prev = start;

		while (ctr < pos)
		{
			prev = temp;
			temp = temp->next;
			ctr++;
		}

		prev->next = temp->next;
		free(temp);
		cout << "Node " << pos << " deleted" << endl;
		
	}
	else
	{
		cout << "Selected position is not in middle\n No changes are made" << endl;
	}
	
}

void insert_in_mid()
{
	node* mylist, * temp, * prev;
	int pos, nodectr, ctr = 1;
	mylist = getnode();
	cout << "Enter the position for the new node:	";
	cin >> pos;
	if (pos < ctr)
	{
		cout << "Position error" << endl;
		return;
	}
	nodectr = node_count();
	if (pos > 1 && pos < nodectr)
	{
		temp = start;
		prev = start;
		while (ctr < pos)
		{
			prev = temp;
			temp = temp->next;
			ctr++;
		}
		prev->next = mylist;
		mylist->next = temp;
		cout << "Node inserted at position: " << pos << endl;
		
	}
	else
	{
		cout << "Position is not in middle" << endl;
	}
	
}
int main()
{
	int n/*,q*/;
	cout << "Enter number of nodes:	";
	cin >> n;

	create(n);
	/*q = node_count();
	cout << q << endl;*/
	cout << "/////////////////////////////////////" << endl;
	read();
	cout << "/////////////////////////////////////" << endl;
	delete_from_mid();
	cout << "/////////////////////////////////////" << endl;
	read();
	cout << "/////////////////////////////////////" << endl;
	insert_in_mid();
	cout << "/////////////////////////////////////" << endl;
	read();
	cout << "/////////////////////////////////////" << endl;
	delete_from_mid();
	cout << "/////////////////////////////////////" << endl;
	read();
	create(n);
	cout << "/////////////////////////////////////" << endl;
	read();

	return 0;

}

