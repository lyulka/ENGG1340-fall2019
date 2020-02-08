#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;


struct Car {
	string id;
	Car *next;
};

void appendCar(Car *&, string id);
void printTrain(Car *&head);

int main() {
	Car *head = NULL;
	int n;
	cin >> n;
	string id;
	for (int i = 0; i < n; i++) {
		cin >> id;
		appendCar(head, id);
	}
	printTrain(head);

	return 0;
}

// Please implement the function appendCar() here.
void appendCar(Car *&head, string id) { // take a pointer parameter by reference
	Car *newCar = new Car;
	newCar->id = id;
	newCar->next = NULL;

	if (head == NULL) {
		head = newCar;
	} else {
		// Under this paradigm, we're not creating any null pointers
		Car *tail = head;

		while (tail->next != NULL) {
			tail = tail->next; // the arrow operator must have some special meaning
		}

		(*tail).next = newCar; // this is equivalent to tail->next (member access operator)
		// tail->next is legit* head->next and used to be a null pointer. 
		// now it's reassigned.

		// Under this paradigm, tail is a null pointer
		// Car *tail = head->next;

		// while (tail != NULL) {
		// 	tail = tail->next;
		// }

		// tail = newCar;
	}
}

void printTrain(Car *&head) {
	Car *current = head;
	while (current != NULL) {
		if (current->next != NULL) {
			cout << current->id << ", ";
		}
		else {
			cout << current->id;
		}
		current = current->next;
	}
}

