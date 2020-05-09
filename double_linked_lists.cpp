#include <iostream>

using namespace std;

class dlinklist {
public:
	class dlinklist *left;
	string data;
	class dlinklist* right;

};

typedef class dlinklist node;
node* start = NULL;

//creates a node
node* getnode()
{
	node* newnode = new node[sizeof(node)];
	
	cout << "Enter data:	";
	cin >> newnode->data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

//creates a list of n nodes
void create(int n)
{
	node* mylist;
	node* temp;
	for (int i = 0; i < n; i++)
	{
		mylist = getnode();
		if (start == NULL)
		{
			start = mylist;
		}
		else
		{
			temp = start;
			while (temp->right != NULL)
			{
				temp = temp->right;

			}

			temp->right = mylist;
			mylist->left = temp; 
		}
	}

}

//inserts a node at the beginning of list when called
void insert_at_beg()
{
	node* newnode;
	newnode = getnode();
	if (start == NULL)
	{
		start = newnode;
	}
	else
	{
		newnode->right = start;
		start->left = newnode;
		start = newnode;
	}
}

//traverses and reads the list
void read()
{
	node* temp;
	temp = start;
	cout << "This list will read from left to right" << endl;
	if (start == NULL)
	{
		cout << "List is empty" << endl;
		return;
	}
	
	while (temp->right != NULL)
	{
		cout << temp->data << endl;
		temp = temp->right;
	}
	cout << temp->data << endl; //accounting for last node
}

//deletes node at the end of the list
void delete_at_end()
{
	node* temp;
	if (start == NULL)
	{
		cout << "list is empty" << endl;
		return;
	}
	temp = start;

	//this checks to see if only single node exists, was getting error if n was 0 or 1.
	//this fixes that issue
	if (temp->right == NULL)
	{
		start = NULL;
		cout << "Only single node exists\nnode has been deleted" << endl;
		return;
	}
	
	while (temp->right != NULL)
	{
		temp = temp->right;
	}
	temp->left->right = NULL;


	 

	cout << "**************************************************" << endl;
	cout << "Node at end deleted" << endl;
}

int main()
{
	int n = 0;

	cout << "Enter number of nodes:	";
	cin >> n;
	create(n);
	cout << "**************************************************" << endl;
	read();
	insert_at_beg();
	cout << "**************************************************" << endl;
	read();
	delete_at_end();
	cout << "**************************************************" << endl;
	read();
	insert_at_beg();
	cout << "**************************************************" << endl;
	read();
	return 0;
}