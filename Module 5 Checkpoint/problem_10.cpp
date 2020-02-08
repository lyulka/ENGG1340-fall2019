#include <iostream>
using namespace std;

int main() {
    for (int i = 6; i >= 0; i--) {
        for (int c = 0; c <= i; c++) {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}