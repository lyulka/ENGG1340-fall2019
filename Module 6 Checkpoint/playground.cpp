#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
    ofstream cfile;
    cfile.open("c.txt", ios::ate | ios::out);

    if (cfile.fail()) {
        cout << "Operation failed" << endl;
        }
}