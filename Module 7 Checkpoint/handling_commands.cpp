#include <iostream>
#include <string>
using namespace std;

int numbers[100];
int count = 0;

void add() {
	int x;
	cin >> x;
	numbers[count] = x;
	count++;
}

void show(){
   for (int i = 0; i < count; i++)
        cout << numbers[i] << " ";
}

float sum(){
    float sum1=0;
    for (int i = 0; i < count; i++)
        sum1 += numbers[i];
      return sum1;
}



int main() {
	string input;
	cin >> input;
	while (input != "exit") {

		if (input == "add") {
			add();
		}
        if(input=="show"){
            show();
        }
        if(input=="count"){
            cout << count;
        }
        if(input=="sum"){
            cout << sum();
        }
        if(input=="average"){
            cout << sum()/count;
        }
        
        
		cin >> input;
	}
	return 0;
}