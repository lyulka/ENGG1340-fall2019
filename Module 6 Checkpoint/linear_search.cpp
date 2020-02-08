#include <iostream>
using namespace std;

int linearSearch(const int array[], int sizeOfArray,
    int key, int startPos);
int main();

int main() {

}

int linearSearch(const int values[], int valuesSize, int key, int startPos) {
    for (int i = startPos; i < valuesSize; i++) {
        if (key == values[i])
            return i;
    }
    return -1;
}

