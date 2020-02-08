#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>
#include <vector>
using namespace std;

class Counter
{
    int number;
    std::mutex mutex;
    public:
    Counter(): number(0){}
    int getNumber() { return number; }
    void increase() {
        mutex.lock();
        number++;
        mutex.unlock();
    }
    void decrease() {
        mutex.lock();
        number--;
        mutex.unlock();
    } 
};

double getLifeTime(int N) {
    return (0.1 + (double) (N % 8));
}

int getNumberOfChildren (int N) {
    return  (( N - (N % 8) ) / 8);
}

void childCell (Counter*& counter, int N) {
    double lifeTime = getLifeTime(N);
    (*counter).increase();
    
    this_thread::sleep_for(chrono::milliseconds((int)(1.0 * 1000 * lifeTime)));
    
    (*counter).decrease();

    return;
}

void genesisCell(Counter*& counter,  int N, vector<std::thread>& activeCells) {
    double lifeTime = getLifeTime(N);
    double numberOfChildren = getNumberOfChildren(N);
    (*counter).increase();
    
    this_thread::sleep_for(chrono::milliseconds((int)(0.5 * 1000 * lifeTime)));
    
    for (int i = 0; i < numberOfChildren; i++) {
        activeCells.push_back(std::thread(childCell, std::ref(counter), N));
    }
    
    this_thread::sleep_for(chrono::milliseconds((int)(0.5 *1000 * lifeTime)));

    (*counter).decrease();

    return;
}

int main() {
    Counter* counter = new Counter();

    cout << "[Main] Please input a list of gene seeds:" << endl << endl;

    // Get values for N from cin
    string input;
    stringstream sInput;
    getline(cin, input);
    sInput << input;

    int N;
    vector<int> nValues;
    while (sInput >> N) {
        nValues.push_back(N);
    }


    // Starting up monitor
    int timeElapsed = 0;
    cout << "[Monitor] Started [ " << timeElapsed << " s ]" << endl << endl;

    vector<std::thread> allCellThreads;

    // Creating new threads
    for (int i = 0; i < nValues.size(); i++) {
        allCellThreads.push_back(std::thread(genesisCell, std::ref(counter), nValues.at(i)), std::ref(allCellThreads));
    }

    while (true) {
        int numberOfActiveCells = counter->getNumber();
        if (numberOfActiveCells == 0) 
            break;

        timeElapsed++;
        cout << "[Monitor] Total cells: " <<  numberOfActiveCells << "[ " << timeElapsed << " s ]" << endl << endl;
        this_thread::sleep_for(chrono::milliseconds((int)(1000)));
    }

    for (int i = 0; i < numberOfActiveCells.size(); i++) {
        (allCellThreads.at(i)).join();
    }
}