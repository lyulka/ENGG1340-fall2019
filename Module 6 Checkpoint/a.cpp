#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double res[20];
    int i = 0;

    while (i < 5) {
        res[i] = sqrt((double) i);
        i++;
    }

    while (i >= 5 && i < 10)  {
        res[i] = 0.0;
        i++;
    }  

    while (i < 20) {
        res[i] = pow(i, 3.0);
        i++;
    }

    for (int i = 0; i < 20; i++) {
        if (i % 2 == 0)
            cout << res[i] << " ";
    }
}