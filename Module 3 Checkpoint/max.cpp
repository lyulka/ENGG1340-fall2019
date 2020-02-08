// Write a program that reads 3 input integers and outputs the maximum one.
#include <iostream>
using namespace std;

int main() {
    int a, b, c;

    cout << "Gimme three integers: ";
    cin >> a;
    cin >> b;
    cin >> c;

    if (a >= b && a >= c)
        cout << "The biggest integer is " << a << "\n";
    else if (b >= a && b >= c)
        cout << "The biggest integer is " << b << "\n";
    else
        cout << "The biggest integer is " << c << "\n";   

    cout << (5 * 7) % 6 << "\n";    
}