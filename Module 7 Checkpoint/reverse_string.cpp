#include <iostream>
#include <string>
using namespace std;

string msg = "hingga mengingkarimu adalah hal yang";

void printReverse(string msg) {
    string temp = "";

    for (int i = msg.length() - 1; i >= 0; i--) 
        temp += msg[i];

    cout << temp << endl;    
}

int main() {
    printReverse(msg);
}