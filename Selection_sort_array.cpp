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

//function will sort intigers
void selection_sort(int*& a, const int length)
{
	int maxindex, tmp;

	for (int i = 0; i < length - 1; i++)
	{
		maxindex = i;

		for (int j = i + 1; j < length; j++)
		{
			if (a[j] < a[maxindex])
			{
				maxindex = j;

			}

			
		}

		tmp = a[i];
		a[i] = a[maxindex];
		a[maxindex] = tmp;
	}

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
	cout << "The unsorted array is:\n ";
	cout << "***********************************************" << endl;
	for (int i = 0; i < n; i++)
	{
		cout<< a[i] << endl;
	}
	cout << "***********************************************" << endl;
	selection_sort(a, n);

	cout << "The sorted array is:\n ";
	cout << "***********************************************" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
	cout << "***********************************************" << endl;

	destroy(a);
	return 0;
}