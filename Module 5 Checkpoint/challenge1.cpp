#include <iostream>
using namespace std;

int main() {
    int cycleCount = 0;
    for (int i = 1; ++i < 10; )
        cycleCount++;

    cout << cycleCount << endl;    
}