#include <iostream>
using namespace std;
int main() {
    int age;
    double height, weight;
    cout << "Please input your age, height, and weight: ";
    cin >> age;
    cin >> height; // Any kind of space character (" ", tab, or newline, is sufficient to separate inputs)
    cin >> weight;
    cout << endl << "Your age is " << age << endl;
    cout << "Your height is " << height << endl;
    cout << "Your weight is " << weight << endl;
    return 0;
}