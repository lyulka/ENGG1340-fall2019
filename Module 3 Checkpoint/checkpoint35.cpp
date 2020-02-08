#include <iostream>
using namespace std;
const int NUM = 10;
const double X = 20.5;

int main() {
    int a, b;
    double p;
    char grade;
    a = 23;
    cout << "a = " << a << endl;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << endl;
    cout << "The numbers you entered are " << a << " and " << b << endl;
    p = X + 2 * a - b;
    cout << "p = " << p << endl;
    grade = 'B';
    cout << "Your grade is " << grade << endl;
    a = 2 * NUM + p;
    cout << "The value of a = " << a << endl;
    return 0;

    // OUTPUT
    // a = 23
    // Enter two integers: 
    // 
    // The numbers you entered are 20 and 25 
    // p = 35.5
    // Your grade is B
    // The value of a = 55 // Remember you're putting a double inside an integer variable.
}