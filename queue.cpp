#include <iostream>

using namespace std;

//add function prototypes


void AddSpace(int *queue, const int back, int max, int front)
{
	max += 1;

	int* t = new int[max];

	for (int i = front; i < back; i++)
	{
		t[i] = queue[i];
	}

	delete[] queue;

	queue = t;

	cout << "Space added" << endl;
}

void display(const int *queue, const int front, const int back )
{
	for (int i = front; i < back; i++)
	{
		cout << "Position " << i << " contains " << queue[i] << endl;

	}


 }

void insert(int* queue, int& back, int& max, int front)
{
	if (back == max)
	{
		cout << "Queue is full, Now adding another cell" << endl;

		AddSpace(queue, back, max, front);

		
	}

	cout << "Insert data: ";
	cin >> queue[back];
	back++;

	cout << "Data has been inserted into the queue" << endl;
}

void remove(int* queue, int& front, const int back)
{
	if (back == 0)
	{
		cout << "Error: Queue is empty.\nReturning to selection" << endl;
	}
	cout << queue[front] << " has been deleted from the queue" << endl;
	front++;
}

int menu(const int back)
{
	int choice;

	if (back == 0)
	{
		cout << "Queue is currently empty" << endl;
	}
	do {
		cout << "Please select one of the following choices\n" << "1 to insert data into queue\n" << "2 to delete data from queue\n" << "3 to display queue\n"
			<< "4 to exit programme\n";

		cin >> choice;

		if (choice < 0 || choice > 4)
		{
			cout << "Error: Invalid choice" << endl;
		}
	} while (choice < 0 || choice > 4);

	return choice;
}

int main()
{
	int max = 2;
	int* queue = new int[max];
	int front = 0;
	int back = 0;
	int ch;
	
	
	do
	{
		ch = menu(back);

		switch (ch) 
		{
		case 1:
			insert(queue, back, max, front);
			break;
		case 2:
			remove(queue, front, back);
			break;
		case 3:
			display(queue, front, back);
			break;
		case 4:
			exit(0);
			break;
		}
	} while (1);


	return 0;
}