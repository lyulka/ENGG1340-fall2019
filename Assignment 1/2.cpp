#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Task 2 - Exponential Calculation

// returns a double x to the power of an integer n
// double pow(int x, int n) {
//     if (x == 0) return 0;

//     double res = 1.0;
//     for (int i = 0; i < n; i++) 
//         res *= x;

//     return res;
// }

// returns the factorial of a double

double fact(int n) {
    if (n == 0 || n == 1) 
        return 1;
    else
        return n * fact(n - 1);
}

// prints estimations of e^x as n increases
void exp(double x, double n) {
    double res = 0;
    
    int i = 0;
    do {
        res += pow(x, i) / fact(i);
        cout << i << " ";
        cout << fixed << setprecision(8);
        cout << res << endl;
        i++;
    } while (i <= n);
}

int main() {

    // getting two integers x and n from standard input.
    double x, n;
    cin >> x >> n;

    // checks if x is in range.
    if (x < 0 || x > 30) 
        return 0;

    exp (x, n);
}