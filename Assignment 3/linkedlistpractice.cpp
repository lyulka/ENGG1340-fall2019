#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* next;
};

int main() {
    Node* head = NULL;
    
    // Building a linked list backward
    Node* p = new Node;
    p->info = 89;
    p->next = head;
    head = p;

    p = new Node;
    p->info = 62;
    p->next = head;
    head = p;

    Node* current = head;
    while (current != NULL) {
        cout << current->info << endl;
        current = current->next;
    }


}