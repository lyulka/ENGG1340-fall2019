#include "binary_search_tree.h"
#include <iostream>
using namespace std;

int main() {
    // Solution to Q2
    // Initialising the BST as showed in Figure 1.
    BinarySearchTree tree;
    tree.insert(8, 25);
    tree.insert(3, 10);
    tree.insert(10, 11);
    tree.insert(1, 20);
    tree.insert(6, 31);
    tree.insert(14, 28);
    tree.insert(4, 17);
    tree.insert(7, 17);
    tree.insert(13, 9);

    // DEBUG
    // tree.print(); cout << endl;
    // tree.print2D();

    // Calling function insert() to add two nodes whose 
    // <id, age> pair are: <2, 49>, <0, 33> to this tree.
    tree.insert(2, 49);
    tree.insert(0, 33);

    // DEBUG
    // tree.print(); cout << endl; 
    // tree.print2D();

    // Calling function remove() to delete node 7 in the tree
    // while keeping the nodes in sorted order.
    tree.remove(7);
    tree.print2D();

    // DEBUG
    // tree.print(); cout << endl;
    // tree.print2D();

    // Solution to Q3
    // Calling function search() to query the age of the patient
    // whose identity is 13.
    int res = tree.search(13);
    if (res != BinarySearchTree::NOT_FOUND) {
        cout << "The patient's age is " << res << endl;
    }

    /* ### DEBUG ONLY ###
    // DEBUG: INSERT FUNCTIONALITY
    // BinarySearchTree tree;
    // tree.insert(50, 50);
    // tree.insert(30, 30);
    // tree.insert(70, 70);
    // tree.insert(20, 20);
    // tree.insert(40, 40);
    // tree.insert(60, 60);
    // tree.insert(80, 80);
    // tree.print(tree.root);

    // DEBUG: SEARCH FUNCTIONALITY
    // int res = tree.search(1);
    // if (res != BinarySearchTree::NOT_FOUND) {
    //     cout << res << endl;
    // }

    // DEBUG: REMOVE FUNCTIONALITY
    // tree.print(tree.root);
    // cout << endl;
    // tree.remove(40);
    // tree.print(tree.root);
    ### END DEBUG ### */
}