#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int length;
    cin >> length;

    int *set = new int[length]();

    for (int i = 0; i < length; i++)
        cin >> set[i];

    sort(set, set + length);

    int curNum = set[0]; // get first value in the sorted array
    int count = 1; // initialised to 1 'cuz set[0] trivially has at least one instance in set
    int curMode = curNum;
    int countMode = count;

    for (int i = 0; i < length; i++) {
        if (set[i] == curNum)
            count++;
        else {
            if (count > countMode) {
                curMode = count;
                countMode = curNum;
            }
            count = 1;
            curNum = set[i];
        }
    }

    cout << "The mode of the set is " << curMode;

    delete[] set;
}