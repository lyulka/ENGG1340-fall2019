#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "Give me up to 8 characters!" << endl;

    char temp;
    char res[8];
    int i = 0;

    for (int i = 0; i < 8; i++) {
        cin >> temp;
        res[i] = temp;
    }

    for (int i = 7; i >= 0; i--) 
        cout << res[i];

    return 0;    
}