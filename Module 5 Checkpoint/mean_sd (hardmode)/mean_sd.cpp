#include <iostream>
#include <math.h>
#include "mean_sd.h"
using namespace std;

double inputs[5];

void mean_sd::getInput() {
    for (int i = 0; i < 5; i++) {
        cin >> inputs[i];
    }
}

double mean_sd::getMean() {
    double temp;

    for (int i = 0; i < 5; i++) {
        temp += inputs[i];
    }

    return temp / sizeof(inputs);
}

double mean_sd::getSd() {
    double mean =  getMean(), res = 0;

    for (int i = 0; i < 5; i++) {
        res += (inputs[i] - mean) * (inputs[i] - mean);
    }
    
    return sqrt(res / 5);
}

int main() {
    mean_sd meanSd;

    meanSd.getInput();
    cout << meanSd.getMean() << endl;
    cout << meanSd.getSd() << endl;

    return 0;
}