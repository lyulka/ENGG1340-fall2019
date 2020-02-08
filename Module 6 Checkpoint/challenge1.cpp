#include <iostream>
#include <math.h>
using namespace std;

int primes_100[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,
                    59, 61, 67, 71, 73, 79, 83, 89, 97};

void primeFactorisation(int val) {
    int temp = val;
    string x = "";

    while (temp != 1) {
        for (int i = 0; i < 25; i++) {
            if (temp % primes_100[i] == 0)  {
                temp = temp / primes_100[i];
                cout << x << primes_100[i];
                x = "x";
                break;
            }
        }
    }
    cout << endl;
}

int main() {
    int v = 48;

    primeFactorisation(v);
}