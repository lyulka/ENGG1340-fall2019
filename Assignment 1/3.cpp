#include <iostream>
#include <string>
using namespace std;

// Task 3 - Digits Permutations

string join(int digits[], int len) {
    string res;

    for (int i = 0; i < len; i++)
        res += to_string(digits[i]);

    return res;
}

string removeTrailingZeroes(string t) {
    while(t[0] == '0')
        t.replace(t.find("0"), 1, "");

    return t;
}

int main() {
    // Get a positive integer M as input
    int m;
    cin >> m;

    // Split up integer base-10 digits into an array (program can handle numbers up to 100 digits long)
    int digits[100];
    int len = 0;
    while (m) {
        digits[len++] = m % 10;
        m /= 10;
    }

    // Sort digits array to prepare it for next_permutation
    sort(digits, digits + len);

    int p = 0; // Counts number of permutations.

    string res; // String which will be output into cout

    do {
        res += removeTrailingZeroes(join(digits, len)) + " ";
        p++;
    } while (next_permutation(digits, digits + len));
    // Removes trailing space
    res.replace(res.rfind(" "), 1, "");

    cout << p << " " << res;
}