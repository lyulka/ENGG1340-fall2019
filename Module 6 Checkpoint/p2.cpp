#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Initialise working array.
    bool values[1000];
    for (int i = 2; i < 1000; i++) 
        values[i] = true;

    // Sieve of Erathosthenes.
    for (int i = 2; i < 1000; i++) {
        if (values[i]) 
            for (int c = i + 1; c < 1000; c++) 
                if (c % i == 0)
                    values[c] = false;
    }

    // Print out the results.
    cout << "Prime numbers between 2 and 1000:" << endl;
    for (int i = 2; i < 1000; i++) 
        if (values[i])
            cout << i << endl;
}