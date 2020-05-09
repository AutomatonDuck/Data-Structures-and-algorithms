#include <iostream>


using namespace std;


void EEA(int a, int b)
{
	int s = 0, old_s = 1, t = 1, old_t = 0, r = b, old_r = a, q, temp;

	/*cout << old_r / r << endl;*/
	while (r != 0)
	{
		q = old_r / r;
		
		temp = old_r;
		old_r = r;
		
		r = temp - q * r;
		
		if (r != 0) //without this the s and t values will go beyond when r = 0, giving wrong values for s and t
		{
			temp = old_s;
			old_s = s;

			s = temp - q * s;
			/*cout << s << endl;*/
			temp = old_t;
			old_t = t;

			t = temp - q * t;
			/*cout << t << endl;*/
		}
	}
	cout << "GCD = " << old_r << endl;
	cout << "s = "<< s << endl <<"t = " << t << endl;
}

int main()
{
	int x, y;
	cout << "Please enter 2 integers to find their greatest commmon denominator: " << endl;
	cin >> x >> y;
	if (x < y)
	{
		swap(x, y);
	}

	cout << "********************************" << endl;
	EEA(x, y);
	cout << "********************************" << endl;

	
}