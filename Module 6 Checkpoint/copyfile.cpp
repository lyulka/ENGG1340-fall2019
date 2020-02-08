#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char fileInput[100], fileOutput[100];
    cout << "Input file: ";
    cin >> fileInput;
    cout << "Output file: ";
    cin >> fileOutput;

    ifstream streamInput(fileInput);
    ofstream streamOutput(fileOutput);

    string buffer;

    while (getline(streamInput, buffer)) 
        streamOutput << buffer << endl;

    streamInput.close();
    streamOutput.close();    
}