/*
   This program prints out the perfect numbers between 1 and N
*/

#include <iostream>
using namespace std;

const int N = 1000;

bool isPerfect(int n) {
    int max = n - 1, temp = 0;

    for (int i = 1; i <= max; i++) {
        if (n % i == 0)
            temp += i;
    }

    return temp == n;
}

int main()
{
	cout << "For the integers from 1 to " << N << ":\n";

	for (int j = 2; j <= N; ++j)
		if (isPerfect(j))
			cout << j << " is perfect\n";

	cout << endl;

	return 0;
}