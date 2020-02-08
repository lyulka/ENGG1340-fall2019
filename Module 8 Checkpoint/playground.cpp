#include <iostream>
using namespace std;

// write a function that takes an integer array and its size,
// and returns a pointer to the largest element in the array.
int* getLargestElement(int array[], int size) {
    int* max = &(array[0]);
    for(int i = 0; i < size; i++)
        array[0] > *max ? max = &(array[0]) : max;

    return max;
}

void swapPointers(int*& a, int*& b) {
    int* c = a;
    a = b;
    b = c;
}

void swapMemory(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void addOne(int &p) {
    p += 1;
}

void addOne(int *p) {
    *p += 1;
}

int main() {
    int n = 5;
    int m = 10;
    int* a = &n;
    int* b = &m;

    swapPointers(a, b);

    cout << *a << endl;
    cout << *b << endl;
}