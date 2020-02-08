#include<iostream>
using namespace std;

void my_swap(int&, int&);

int main();

void my_swap(int& n, int& m) {
    int temp = n;
    n = m;
    m = temp;
}

int main()
{
	int a[100];
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < (n - i); ++j)
			if (a[j] > a[j + 1]) {
				my_swap(a[j], a[j + 1]);
			}
	}

	cout << "Array after bubble sort:\n";
	for (int i = 0; i < n; ++i) {
		cout << " " << a[i];
	}

	return 0;
}