#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Task 1 - Puppies

void isTooFar(int queenie[2], int puppies[][2], int n) {
    // number of puppies that are too far from queenie
    int tooFar = 0;

    // loops through puppies and checks each if they're too far from queenie
    string delineator = "";
    for (int i = 1; i < n + 1; i++) {
        if (sqrt(pow((puppies[i][0] - queenie[0]), 2.0) + pow((puppies[i][1] - queenie[1]), 2.0)) > 10.0) {
            cout << delineator;
            cout << "Puppy " << i;
            delineator = " and ";
            tooFar++;
        }     
    }
    if (delineator != "") 
        cout << " too far away" << endl;

    if (tooFar == 1)
        cout << "Total " << tooFar << " puppy too far away";
    else if (tooFar > 1)
        cout << "Total " << tooFar << " puppies too far away";
    else 
        cout << "No puppies too far away";
}

int main() {
    // Getting Queenie's position
    int queenie[2];
    cin >> queenie[0] >> queenie[1];

    // Getting integer representing the number of puppies
    int n;
    cin >> n;

    // Getting n pairs of integers indicating the x and y locations of Puppy 1 to Puppy n
    int puppies[1000][2]; 
    for (int i = 1; i < n + 1; i++)
        cin >> puppies[i][0] >> puppies[i][1];

    isTooFar(queenie, puppies, n);
}