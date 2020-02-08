#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Task 5 - One-shot Stock Trader
// TODO: Re-read the fucking task description.

int main() {

    // Setting up stringstream and getting input
    string input;
    stringstream sInput;
    getline(cin, input);
    sInput << input;

    // Looping through input and placing all elements into a vector
    int curPrice;
    vector<int> stockPrices;
    while (sInput >> curPrice)
        stockPrices.push_back(curPrice);

    int i = 1;
    // initialising positiveGradient to be the gradient at the very start of the 'graph'
    bool positiveGradient = stockPrices.at(0) < stockPrices.at(1);

    vector<int> inflectionPrices;
    // Place the first value of stockPrices into inflectionPrices
    inflectionPrices.push_back(stockPrices.at(0));

    // Looping through input and putting all stationary points into inflectionPrices, skipping the first value
    while (i + 1 <= stockPrices.size() - 1) {
        if (i + 1 == stockPrices.size() - 1) { // get the very last stock price
            inflectionPrices.push_back(stockPrices.at(i + 1));
        } else if (stockPrices.at(i) < stockPrices.at(i + 1) != positiveGradient) {
            inflectionPrices.push_back(stockPrices.at(i));
            positiveGradient = !positiveGradient;
        } 
        i++;
    }

    // // Sorting input
    // sort(stockPrices.begin(), stockPrices.end());

    // cout << stockPrices.at(stockPrices.size() - 1) - stockPrices.at(0);

    // Looping through inflection finding biggest positive delta between pairs
    int maxDelta = 0;
    int priceDelta = 0;
    for (int i = 0; i < inflectionPrices.size() - 1; i++) {
        for (int c = i + 1; c < inflectionPrices.size(); c++) {
            priceDelta = inflectionPrices.at(c) - inflectionPrices.at(i);
            if (priceDelta > maxDelta)
                maxDelta = priceDelta;
        }
    }

    cout << maxDelta;
}