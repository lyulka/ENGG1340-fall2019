#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e;
    cout << "Input 5 integers:" << endl; 
    cin >> a >> b >> c >> d >> e;
    int values[5] = {a, b, c, d, e};

    int sumPositive = 0, sumNegative = 0, sumTotal = 0;
    for (int i = 0; i < 5; i++) {
            if (values[i] > 0)
                sumPositive += values[i];
            else if (values[i] < 0)
                sumNegative += values[i];
            sumTotal += values[i];
    }

    cout << "Sum of positive integers: " << sumPositive << endl;
    cout << "Sum of negative integers: " << sumNegative << endl;
    cout << "Sum of all integers: " << sumTotal << endl;
}