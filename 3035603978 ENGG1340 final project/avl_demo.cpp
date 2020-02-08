#include "avl_tree.h"
using namespace std;

int main() {

    // Solution to Q2
    // Initialising the BST as showed in Figure 1.
    AvlTree tree;
    tree.insert(8, 25);
    tree.insert(3, 10);
    tree.insert(10, 11);
    tree.insert(1, 20);
    tree.insert(6, 31);
    tree.insert(14, 28);
    tree.insert(4, 17);
    tree.insert(7, 17);
    tree.insert(13, 9);

    // // Calling function insert() to add two nodes whose 
    // // <id, age> pair are: <2, 49>, <0, 33> to this tree.
    tree.insert(2, 49);
    tree.insert(0, 33);

    // // Calling function remove() to delete node 7 in the tree
    // // while keeping the nodes in sorted order.
    tree.remove(7);

    // // DEBUG
    tree.print2D();

    // // Solution to Q3
    // // Calling function search() to query the age of the patient
    // // whose identity is 13.
    // int res = tree.search(13);
    // if (res != AvlTree::NOT_FOUND) {
    //     cout << "The patient's age is " << res << endl;
    // }

    // tree.insert(7, 7);
    // tree.insert(8, 8);
    // tree.insert(3, 3);
    // tree.insert(5, 5);
    // tree.insert(1, 1);
    // tree.insert(2, 2);
    // tree.print2D();

    // // ### DEBUG ONLY ###
    // // DEBUG: INSERT FUNCTIONALITY
    // AvlTree tree1;
    // tree1.insert(50, 50);
    // tree1.insert(30, 30);
    // tree1.insert(70, 70);
    // tree1.insert(20, 20);
    // tree1.insert(40, 40);
    // tree1.insert(60, 60);
    // tree1.insert(80, 80);
    // tree1.print();

    // // DEBUG: SEARCH FUNCTIONALITY
    // int res1 = tree1.search(1);
    // if (res1 != AvlTree::NOT_FOUND) {
    //     cout << res1 << endl;
    // }

    // // DEBUG: REMOVE FUNCTIONALITY
    // tree1.print();
    // cout << endl;
    // tree1.remove(40);
    // tree1.print();
    // // ### END DEBUG ###
}