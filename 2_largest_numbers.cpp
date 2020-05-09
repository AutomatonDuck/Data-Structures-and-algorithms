#include <iostream>
using namespace std;

//Fucntion will ask for array size and elements
int array_init(int*& a)
{
	int n;
	cout << "Enter the number of elements you wish to sort: ";
	cin >> n;
	a = new int[n];
	cout << "Enter the " << n << " elements you wish to sort: " << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "Element " << i + 1 << endl;
		cin >> a[i];
	}
	return n;
}

//finds two largest elements in one pass
void Twolargest(int*& a, const int n)
{
	int largest = a[0], secondlargest = a[0]; //initalizing to the first element to avoid using a number that may be outside the range of a given value. (i.e. using zero when all elements are negative)
	for (int i = 0; i < n; i++)
	{
		if (a[i] > largest)
		{
			secondlargest = largest;
			largest = a[i];
		}
		else if (secondlargest < a[i])
		{
			secondlargest = a[i];
		}
	}

	cout << "*********************************************" << endl;
	cout << "The largest number is : " << largest << endl << "The second largest number is: " << secondlargest << endl;
	cout << "*********************************************" << endl;
}

//unallocate memory
void destroy(int*& a)
{

	delete[] a;
}

int main()
{
	int* a = new int[1], n;

	n = array_init(a);
	
	Twolargest(a, n);

	destroy(a);
	return 0;
}