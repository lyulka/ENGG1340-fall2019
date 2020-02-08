#include <iostream>
#include "binary_search_tree.h"
using namespace std;

// From the wikipedia page for Binary Search Trees
// ... the key in each node must be greater than or 
// equal to any key stored in the left sub-tree, and 
// less than or equal to any key stored in the right
// sub-tree. The leaves (final nodes) of the tree contain
// no key and have no structure to distinguish them from
// one another.

Node::Node(int id, int age) {
    this->id = id;
    this->age = age;
    this->leftChild = NULL;
    this->rightChild = NULL;
}

const int BinarySearchTree::NOT_FOUND = 694201337;

BinarySearchTree::BinarySearchTree() {
    this->root = NULL;
}

// DEBUG ONLY; wrapper for print(Node)
void BinarySearchTree::print() {
    if (root != NULL) {
        print(root);
    }
}

// DEBUG ONLY
// Prints all elements in sorted ascending order
void BinarySearchTree::print(Node *node) { 
    if (node != NULL) { 
        print(node->leftChild); 
        cout << "<" << node->id << ", " << node->age << "> ";
        print(node->rightChild); 
    } 
}

// DEBUG ONLY; wrapper for print2D(Node, int)
// Retrieved from the fine lads at geeksforgeeks.com
void BinarySearchTree::print2D() {
    print2D(root, 0);
}

// DEBUG ONLY
// Prints all elements in tree-like 2D form.
// Retrieved from the fine lads at geeksforgeeks.com
void BinarySearchTree::print2D(Node *node, int space)  
{  
    // Base case  
    if (node == NULL)  
        return;  

    // Increase distance between levels  
    space += 10;  

    // Process right child first  
    print2D(node->rightChild, space);  

    // Print current node after space  
    // count  
    cout << endl;  
    for (int i = 10; i < space; i++)  
        cout << " ";  
    cout << node->id << "\n";  

    // Process left child  
    print2D(node->leftChild, space);  
} 

// Insert a new Node into the BST, by 
// pointing the previously null leftChild or rightChild
// of an existing Node in the BST to a new Node with id and age specified,
// left if the id given is smaller that the existing Node's ID, and right
// if the id given is larger than the existing Node's ID.
// If the ID matches that of a node, then it will be rejected and not inserted.
// A message will be printed on standard out informing the user of this.
void BinarySearchTree::insert(int id, int age) {
    // The to-be-inserted Node.
    Node* node = new Node(id, age);

    // start building a tree if not built yet
    if (this->root == NULL) {
        this->root = node;
        cout << "New tree initialised with root id " << id << endl;
        return;
    }

    Node* curNode = this->root;
    bool complete = false;
    while (!complete) {
        // If the id of the Node to be inserted matches one already in the tree, exit.
        if (id == curNode->id) {
            cout << "Non unique element ID: " << id << " entered." << endl;
            complete = true;
            delete node; // clean up the unused memory assigned to the redundant to-be-inserted node.
        } 
        // If the id of the Node to be inserted is smaller than curNode,
        // check its leftChild
        else if (id < curNode->id) {
            // if leftChild is a nullpointer, reassign it to the memory address of the new Node.
            if (curNode->leftChild == NULL) {
                curNode->leftChild = node;
                complete = true;
            // if it isn't, then rebind curNode to its leftChild.
            } else {
                curNode = curNode->leftChild;
            }
        } 
        // If the id of the Node to be inserted is larger than curNode,
        // rebind curNode to its rightChild.
        else if (id > curNode->id) {
            // if rightChild is a nullpointer, reassign it to the memory address of the new Node.
            if (curNode->rightChild == NULL) {
                curNode->rightChild = node;
                complete = true;
            // if it isn't, then rebind curNode to its rightChild.
            } else {
                curNode = curNode->rightChild;
            }
        }
    }
    return;
}

// returns a pointer to the Node in the BST with a given id.
// End cases: 1. The tree is empty (null).
// 2. A Node with the specified ID is found.
// 3. A leaf is found (both leftChild and rightChild are NULL).
Node* BinarySearchTree::get(int id) {
    Node* curNode = root;
    while (true) {
        if (curNode == NULL) {
            return NULL;
        }

        if (id == curNode->id) {
            return curNode;
        } else if (id < curNode->id) {
            curNode = curNode->leftChild;
        } else {
            curNode = curNode->rightChild;
        }
    }
}

// Wrapper for remove(Node*, int); The user will mainly start remove operations using this function,
// however, the main logic of the operation is in the function after this one.
void BinarySearchTree::remove(int id) {
    if (root == NULL) {
        cout << "This binary search tree has not been initialised!" << endl;
    } else {
        remove(this->root, id);
    }

    return;
}

// Delete the Node with the same id as specified, and,
// If (1) the removed Node has no children, no further action is taken.
// If (2) the removed Node has one child, the child will be destroyed
// and re-inserted in place of the destroyed parent.
// If (3) the removed Node has two children, the largest id Node from its left child-tree
// will be destroyed and re-inserted in place of the destroyed parent.
// Both (2) and (3) involves recursive calls to remove.
// The function simply returns either a pointer to a Node, or NULL.
Node* BinarySearchTree::remove(Node* curNode, int id) {

    // If curNode hits a leaf, there are two possible base cases...
    if (curNode->leftChild == NULL && curNode->rightChild == NULL) {
        // Case (1), successful removal base case
        if (id == curNode->id) {
            delete curNode;
            return NULL;
        // Search and removal unsuccessful case.
        } else if (id != curNode->id) {
            cout << "The Node with id: " << id << " was not found and not removed." << endl;
            return curNode;
        }
    }
    
    // Traverse the tree looking for target
    if (id < curNode->id) {
        curNode->leftChild = remove(curNode->leftChild, id);
        return curNode;
    } else if (id > curNode->id) {
        curNode->rightChild = remove(curNode->rightChild, id);
        return curNode;
    } else {
        // Case (2) leftChild present.
        } if (curNode->leftChild != NULL && curNode->rightChild == NULL) {
            Node* replacementNode = curNode->leftChild;
            delete curNode;
            return replacementNode;
        // Case (2) rightChild present.
        } else if (curNode->leftChild == NULL && curNode->rightChild != NULL) {
            Node* replacementNode = curNode->rightChild;
            delete curNode;
            return replacementNode;
        }
        // Case (3) to-be-removed Node has two children.
        else if (curNode->leftChild != NULL && curNode->rightChild != NULL) {
            Node* replacementNode = curNode->rightChild;

            // Search for the smallest id Node from the to-be-removed Node's left
            // child-tree. (the inorder / next largest Node to the one to-be-removed)
            while (replacementNode->leftChild != NULL) {
                replacementNode = replacementNode->leftChild;
            }
            
            // Replace the to-be-removed Node's id and age with that of the replacementNode.
            curNode->id = replacementNode->id;
            curNode->age = replacementNode->age;

            // Remove the now re-inserted Node (the original replacementNode).
            curNode->rightChild = remove(curNode->rightChild, replacementNode->id);

            return curNode;
        }

        // this statement should theoretically never be reached.
        cout << "This should not have been printed out." << endl;
        return NULL;
    }

// Searches for a Node with specified id and returns its value.
int BinarySearchTree::search(int id) {
    if (root == NULL) {
        cout << "This binary search tree has not been initialised!" << endl;
        return NOT_FOUND;
    } 

    Node* res = get(id); // uses get to obtain a pointer to the node with given id, if it exists in the BST.
    if (res == NULL) {
        cout << "The Node with id: " << id << " was not found." << endl;
        return NOT_FOUND;
    } else {
        return res->age; 
    }
}