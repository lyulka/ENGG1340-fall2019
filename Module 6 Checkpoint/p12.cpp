#include <iostream>
#include <fstream>
using namespace std;

struct Entry {
    string firstName;
    string lastName;
    char grade;
    int age;
};

void printEntry(Entry entry) {
    cout << entry.firstName << ", " << entry.lastName << ", "
        << entry.grade << ", " << entry.age << endl;
}

int main() {
    Entry entries[5];
    ifstream fin("lab08-p6.txt");

    for (int r = 0; r < 5; r++) 
        fin >> entries[r].firstName >> entries[r].lastName 
            >> entries[r].grade >> entries[r].age;

    for (int i = 0; i < 4; i++) 
        printEntry(entries[i]);
}