#include <iostream>

using namespace std;

struct Contestant
{
	int id;
	Contestant* next;
};

void print_list(Contestant* head)
{
    Contestant * current = head;
	while (current != NULL)
	{
		// process the current Contestant, e.g., print the content
		cout << current->id << " -> ";
		current = current->next;
	}
	cout << "NULL\n";
}

void tail_insert(Contestant*& head,
	Contestant*& tail, int num)
{
	Contestant * p = new Contestant;
	p->id = num;
	p->next = NULL;

	if (head == NULL) {
		head = p;
		tail = p;
	} else {
		tail->next = p;
		tail = p;
	}
}

void eliminate(Contestant*& head, int k) {
	// head pointer will move forward k - 1 steps here,
	// and one additional step outside of the loop.
	for (int i = 0; i < k - 1; i++) {
		head = head->next;
	}

	// initialising a pointer pointing to the selected-to-be-eliminated contestant.
	Contestant* p = head->next;
	head->next = p->next;

	// move the head one position forwards as to continue the process
	// from the contestant to the next of the one that is going to be
	// eliminated.
	head = p->next;
	delete p;
}

int main()
{
    Contestant * head = NULL, * tail = NULL;
    
    // get values for n and k from cin
    int n; int k;
	cin >> n >> k;

	// creating the original list forwards
    for (int i = 1; i <= n; i++) {
        tail_insert(head, tail, i);
    }

    // connect the tail to the head.
    tail->next = head;

    // actually start removing the k+1-th contestants from the circle
	// stop condition is when head->next points to head itself,
	// which implies that only one contestant is left in the linked list.
	while (head->next != head) {
		eliminate(head, k);
	}

	// print out the one remaining contestant.
	cout << head->id;
}
