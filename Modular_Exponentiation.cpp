#include <iostream>
#include <vector>

using namespace std;

vector <int> BinaryK(int k)
{
	int tmp = k, i = 0;
	vector <int> K;

	while (tmp > 0)
	{
		K.push_back(tmp % 2); // fills vector from back to front to avoid having to flip array

		tmp = (tmp - K[i]) / 2;
		i++;
	}

	return K;
}

//will find the remainder of modular exponent
int ME(int a, vector <int> K, int n, int k)
{
	int b = 1;

	if (n == 1)
	{
		return 0;
	}

	if (k == 0)
	{
		return b;
	}

	int A = a;

	if (K[0] == 1) //test for odd binary number
	{
		b = a;
	}

	for (int i = 1; i < K.size(); i++)// start at one since lsb was check by previous if statement 
	{
		A = A * A % n;
		if (K[i] == 1)
		{
			b = A * b % n;
		}
	}
	cout << endl << a << "^" << k << "mod" << n << "=" << endl;
	return b; //will return remainder
}


int main()
{
	int k, j, a, n;


	cout << endl << "Please Enter an base to be raised by the exponent: ";
	cin >> a;
	cout << "Please enter a value for an exponent: ";
	cin >> k;
	cout << endl << "Please enter the modulous: ";
	cin >> n;

	vector <int> K (BinaryK(k));

	//testing the values of the vector
	/*for (int i = 0; i < K.size(); i++)
	{
		cout << K[i];
	}*/

	cout << endl << "b = " << ME(a, K, n, k) << endl;
	return 0;
}