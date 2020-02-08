#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

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

    // Checking the validity of the data
    if (stockPrices.size() < 2)
        return 0;

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

    // Looping through inflection points checking for positive deltas between pairs
    i = 0;
    int sumProfits = 0;
    int priceDelta = 0;
    while (i + 1 <= inflectionPrices.size() - 1) {
        priceDelta = inflectionPrices.at(i + 1) - inflectionPrices.at(i);
        if (priceDelta > 0)
            sumProfits += priceDelta;
        i++;
    }
    
    std::cout << sumProfits;
}