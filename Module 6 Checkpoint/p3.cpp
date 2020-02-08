#include <iostream>
#include <iomanip>
using namespace std;

void swapFrontBack(int val[], int valSize) {
    bool res = false;
    for (int i = 0; i < valSize; i++) 
        if (val[i])  {
            res = true;
            break;
        };

    if (res == false)
        cout << "swapFrontBack: This shit is broken man" << endl;
    else {
        int temp = val[0];
        val[0] = val[valSize - 1];
        val[valSize - 1] = temp;
    }
    return;    
}
int main() {
    int input[6] = {};

    swapFrontBack(input, 0);

    for (int i = 0; i < 6; i++) 
        cout << input[i] << endl;
}