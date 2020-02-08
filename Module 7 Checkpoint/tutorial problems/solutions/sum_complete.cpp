#include <iostream>

using namespace std;

/*
// iterative version
int sum( int n )
{
	int sum = 0;

	for (int i = 1; i <= n; ++i)
		sum += i;
	
	return sum;
}
*/

// recursive versioln
int sum( int n )
{
	if (n == 1)
		return 1;
	else
		return n + sum(n-1);

}

int main()
{
	int n;

	cout << "Enter a positive integer: ";
	cin >> n;

	cout << "Sum of first " << n << " natural numbers = " << sum(n) << endl; 

	return 0;
}