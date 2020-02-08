#include <iostream>
#include <algorithm>
#include <string>
#include "Threadpool.h"
#include <condition_variable>
#include <functional>
#include <future>
#include <vector>
#include <thread>
#include <queue>
#include <mutex>

class Node {
    public:
    int id;
    int age;
    Node* leftChild;
    Node* rightChild;

    Node(int id, int age) {
        this->id = id;
        this->age = age;
        this->leftChild = NULL;
        this->rightChild = NULL;
    }
};

class BinarySearchTree {
    public:
    Node* root;

    // Arbitrary value used to indicate to the main thread that search
    // failed to find an element with the given ID.
    static const int NOT_FOUND = -694201337; 

    BinarySearchTree() {
        this->root = NULL;
    }
    
    // DEBUG ONLY; wrapper for print(Node)
    void print() {
        if (root != NULL) {
            print(root);
        }
    }

    // DEBUG ONLY
    // Prints all elements in sorted ascending path
    void print(Node *node) { 
        if (node != NULL) { 
            print(node->leftChild); 
            std::cout << "<" << node->id << ", " << node->age << "> ";
            print(node->rightChild); 
        } 
    }


    // #### DEBUG ONLY ####
    // wrapper for print2D(Node, int)
    // Retrieved from the fine lads at geeksforgeeks.com
    void print2D() {
        print2D(root, 0);
    }

    // Prints all elements in tree-like 2D form.
    // Retrieved from the fine lads at geeksforgeeks.com
    void print2D(Node *node, int space)  
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
    std::cout << std::endl;  
    for (int i = 10; i < space; i++)  
        std::cout << " ";  
    std::cout << node->id << "\n";  
  
    // Process left child  
    print2D(node->leftChild, space);  
} 

    // #### END OF DEBUG FUNCTIONS ####

    // Insert a new Node into the BST, by 
    // pointing the previously null leftChild or rightChild
    // of an existing Node in the BST to a new Node with id and age specified,
    // left if the id given is smaller that the existing Node's ID, and right
    // if the id given is larger than the existing Node's ID.
    // If the ID matches that of a node, then it will be rejected and not inserted.
    // A message will be printed on standard out informing the user of this.
    void insert(int id, int age) {
        // The to-be-inserted Node.
        Node* node = new Node(id, age);

        // start building a tree if not built yet
        if (this->root == NULL) {
            this->root = node;
            std::cout << "New tree initialised with root id " << id << std::endl;
            return;
        }

        Node* curNode = this->root;
        bool complete = false;
        while (!complete) {
            // If the id of the Node to be inserted matches one already in the tree, exit.
            if (id == curNode->id) {
                std::cout << "Non unique element ID: " << id << " entered." << std::endl;
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
    Node* get(int id) {
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
    void remove(int id) {
        if (root == NULL) {
            std::cout << "This binary search tree has not been initialised!" << std::endl;
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
    Node* remove(Node* curNode, int id) {

        // If curNode hits a leaf, there are two possible base cases...
        if (curNode->leftChild == NULL && curNode->rightChild == NULL) {
            // Case (1), successful removal base case
            if (id == curNode->id) {
                delete curNode;
                return NULL;
            // Search and removal unsuccessful case.
            } else if (id != curNode->id) {
                std::cout << "The Node with id: " << id << " was not found and not removed." << std::endl;
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
            std::cout << "This should not have been printed out." << std::endl;
            return NULL;
        }

    // Searches for a Node with specified id and returns its value.
    int search(int id) {
        if (root == NULL) {
            std::cout << "This binary search tree has not been initialised!" << std::endl;
            return NOT_FOUND;
        } 

        Node* res = get(id); // uses get to obtain a pointer to the node with given id, if it exists in the BST.
        if (res == NULL) {
            std::cout << "The Node with id: " << id << " was not found." << std::endl;
            return NOT_FOUND;
        } else {
            return res->age; 
        }
    }
};

class SearchResult {
public:
    // list of the identities of traversed Nodes
    int identity;
    
    // A string of variable length comprising entirely of the letters
    // "A" and "B." for example: "AAABBA"
    // This string stores the path taken my the traversion leading to the
    // creation of a particular SearchResult object.
    // This is what is ultimately sorted.
    std::string mPath;

    // default constructor
    SearchResult(int identity, std::string path) {
        this->identity = identity;
        this->mPath = path;
    }

    // used to sort results into pre-order order.
    // Compares LHS and RHS SearchResults' mPaths
    // character by character.
    // if a position on both mPaths is reached where
    // first one is A and the other one is B, then the first one
    // goes first in the results, and vice versa.
    // This is used by the std::sort function in ConcurrentTraverse.printResults().
    bool operator< (const SearchResult &other) const {
        int i = 0;
        std::string thisPath = this->mPath;
        std::string otherPath = other.mPath;
        while (i < thisPath.length() && i < otherPath.length()) {
            if (thisPath.at(i) < otherPath.at(i)) {
                return true;
            } else if (thisPath.at(i) > otherPath.at(i)) {
                return false;
            }
            i++;
        }
        // if all so far are good
        return thisPath.length() < otherPath.length();
    }
};

class ConcurrentTraverse {
public:
    // all creedit goes to amc176 for his Threadpool class (https://github.com/amc176/cpp-threadpool/tree/master/Threadpool)
    threadpool::Threadpool mThreadPool{ 8 }; // 8 is set as the default number of threads; I'm assuming most people own hyperthreaded intel CPUs
    std::mutex mutex;
    BinarySearchTree* mTree = NULL;
    bool complete;
    std::vector<SearchResult> mSearchResults;


    // default constructor
    ConcurrentTraverse(BinarySearchTree* tree) {
        // to improve efficiency, enlarge the threadpool to contain as many threads as the environment
        // the program is running on has made available.
        mThreadPool.resize(std::thread::hardware_concurrency());
        this->mTree = tree;
    }

    // DEBUG: testing amc176's threadpool
    int printWow() {
        std::cout << "wow" << std::endl;
        return 1;
    }

    // Preorder traversals follow the recursive ruleset:
    // 1. Visit and store identity of the Node,
    // 2. Recurse to the left subtree, if possible,
    // 3. Recurse to the right subtree, if possible.
    // TraverseLeft is the default behaviour of a thread in ConcurrentTraverse,
    void traverseLeft(Node* node, std::string curPath) {
        std::cout << "Node identity: " << node->id << std::endl;

        // Store the identity of the Node into the currently held chainResults.
        // curPath is also stored for sorting the results into pre-order order later.
        mutex.lock();
        (mSearchResults).emplace_back(SearchResult(node->id, curPath));
        mutex.unlock();

        // base case
        if (node->leftChild == NULL && node->rightChild == NULL) {
            return;
        }

        // start traversing rightwards.
        // note curPath is now appended by B, which signifies a right turn being made.
        if (node->rightChild != NULL) {
            mThreadPool.queueTask(&ConcurrentTraverse::traverseLeft, this, node->rightChild, curPath + "B");
        }

        // start traversing leftwards.
        // curPath is now appended by A, which signifies a left turn being made.
        if (node->leftChild != NULL) {
            traverseLeft(node->leftChild, curPath + "A");
        }

        return;
    }

    // Does the same thing as the function traverseLeft, but does not keep track of pre-order ordering.
    // instead, it prints out the age of the patient with the found id.
    void traverseLeftSearch(Node* node, int id) {

        // Base case 1
        if (node->id == id) {
            std::cout << "The age of the patient with id: " << id << " is " << node->age << std::endl; 
        }

        // Base case 2
        if (node->leftChild == NULL && node->rightChild == NULL) {
            return;
        }
        
        if (node->rightChild != NULL) {
            mThreadPool.queueTask(&ConcurrentTraverse::traverseLeftSearch, this, node->rightChild, id);
        }

        if (node->leftChild != NULL) {
            traverseLeftSearch(node->leftChild, id);
        }

        return;
    }

    // Begins preorder traversal to print all elements of the tree in pre-order ordering.
    void start() {
        // Check whether tree has been initialised yet.
        if (mTree->root != NULL) {
            std::cout << "Starting concurrent search operation" << std::endl;
            mutex.lock();

            // Begin traversing at the root.
            mThreadPool.queueTask(std::bind(&ConcurrentTraverse::traverseLeft, this, mTree->root, ""));
            mutex.unlock();
        } else {
            std::cout << "Tree has not been initialised!" << std::endl;
            return;
        }

        // wait until all threads have ended their execution.
        mThreadPool.waitForTasks();

        printResults();
    }
    
    // Begins preorder traversal to find and print the age of the patient with id given.
    void startSearch(int id) {
        if (mTree->root != NULL) {
            std::cout << "Starting search for node with id: " << id << std::endl;
            mutex.lock();

            mThreadPool.queueTask(std::bind(&ConcurrentTraverse::traverseLeftSearch, this, mTree->root, id));
            mutex.unlock();
        } else {
            std::cout << "Tree has not been initialised!" << std::endl;
            return;
        }

        // wait until all threads have ended their execution.
        mThreadPool.waitForTasks();

        return;        
    }

    // Print the results of concurrent tree traversal in preorder-sorted path
    // into the console.
        void printResults() {
            // sorts the result using the rules defined in SearchResults.operator<
            std::sort(mSearchResults.begin(), mSearchResults.end());

            // format the results in a pretty way.
            std::cout << std::endl;
            std::cout << "######" << std::endl;
            std::cout << "Sorted results of traversal: ";
            for (int i = 0; i < mSearchResults.size(); i++) {
                std::cout << mSearchResults.at(i).identity << " ";
            }
            std::cout << std::endl;
        }
};

// driver function
int main() {
    // Setting up BST as it was done in Task 1 Q1 ~ Q3
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

    tree.insert(2, 49);
    tree.insert(0, 33);

    tree.remove(7);

    // Starting a tree traversal for all members.
    ConcurrentTraverse concurrentTraverse(&tree);
    concurrentTraverse.start();

    // Starting a tree traversal for the patient with id 6.
    concurrentTraverse.startSearch(6);
}