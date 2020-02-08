#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;





int main()
{
	const int SIZE = 10;
	int a[SIZE];

	// initialize random seed
	srand( time(NULL) );

	for (int i = 0; i < SIZE; ++i) 
		a[i] = rand()%100 + 1;

	cout << "array contents: ";
	for (int i = 0; i < SIZE; ++i)
		cout << a[i] << " ";
	cout << endl;

	cout << "the largest element = " << largest_element(a, SIZE) << endl;
	 
	return 0;

}