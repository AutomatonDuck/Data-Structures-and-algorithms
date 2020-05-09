#include <iostream>

using namespace std;

class qlist {

public:

	string data;

	class qlist* next;

};

typedef class qlist node; // sets node as alias for class
node* front = NULL;

node* getnode();
void create();
void display();
void destroy();


node* getnode()
{
	node* queue = new node[sizeof(node)];
	cout << "Enter data for node:\n";
	cin >> queue->data;
	queue->next = NULL;

	return queue;

}

void create()
{

	node* back, * queue;

	queue = getnode();

	if (front == NULL)
	{
		front = queue;
	}
	else
	{
		back = front;
		while (back->next != NULL)
		{
			back = back->next;

		}
		back->next = queue;
	}
}

void display()
{
	node* back;
	back = front;
	cout << "Will read queue from front to back" << endl;
	

	if (front == NULL)
	{
		cout << "*************************************************************************" << endl;
		cout << "Queue is empty" << endl;
		cout << "*************************************************************************" << endl;
		return;
	}

	while (back->next != NULL)
	{
		cout << back->data << endl;
		back = back->next;
	}
	cout << back->data << endl;
}

void destroy()
{
	if (front == NULL)
	{
		cout << "*************************************************************************" << endl;
		cout << "Queue is empty" << endl;
		cout << "*************************************************************************" << endl;
		return;
	}
	cout << front->data << " has been deleted" << endl;
	front = front->next;
}

int menu()
{
	int choice;
	do {
		cout << "*************************************************************************" << endl;
		cout << "Please select one of the following choices\n" << "1 to insert data into queue\n" << "2 to delete data from queue\n" << "3 to display queue\n"
			<< "4 to exit programme\n";
		cout << "*************************************************************************" << endl;
		cin >> choice;

		if (choice < 0 || choice > 4)
		{
			cout << "*************************************************************************" << endl;
			cout << "Error: Invalid choice" << endl;
			cout << "*************************************************************************" << endl;
		}
	} while (choice < 0 || choice > 4);

	return choice;
}

int main()
{
	int ch;
	do
	{
		ch = menu();

		switch (ch)
		{
		case 1:
			create();
			break;
		case 2:
			destroy();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
			break;
		}
	} while (1);

	return 0;
}
