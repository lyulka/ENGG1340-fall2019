#include <iostream>
#include <string>
using namespace std;

string msg1 = "kook";

bool isPalindrome(string t) {
    if (t.length() == 0)
        return false;
    
    for (int i = 0; i < (t.length() / 2 + 1); i++) 
        if (t[i] != t[t.length() - i - 1]) return false;

    return true;
}

int main() {
    cout << isPalindrome(msg1);
}