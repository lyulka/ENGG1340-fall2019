#include <iostream>
using namespace std;

double varOf(double [], int);
double meanOf(double [], int valsSize);
int main();

double varOf(double vals[], int valsSize) {
    double res;
    double mean = meanOf(vals, valsSize);
    for (int i = 0; i < valsSize; i++)
        res += (vals[i] - mean) * (vals[i] - mean);
    res /= valsSize;
    return res;
}

double meanOf(double vals[], int valsSize) {
    double res;
    for (int i = 0; i < valsSize; i++) {
        res += vals[i];
    }

    return res / valsSize;
}

int main() {
    int no_of_inputs;
    cin >> no_of_inputs;

    double inputs[20]; // The length of arrays have to be FIXED at COMPILATION.

    for (int i = 0; i < no_of_inputs; i++)
        cin >> inputs[i];

    cout << "Variance = " << varOf(inputs, no_of_inputs);
}