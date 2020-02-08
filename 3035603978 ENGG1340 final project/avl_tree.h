#pragma once

class Node {
    public:
    int id;
    int age;
    int balanceFactor;
    Node* parent;
    Node* leftChild;
    Node* rightChild;

    Node(int id, int age);

    static int getSubtreeHeight(Node* node);

    void setBalanceFactor();

    Node* rebalance();

    Node* rotateLeft();

    Node* rotateRight();

    Node* rotateRightLeft();

    Node* rotateLeftRight();
};

class AvlTree {
    public:
    Node* root;

    static const int NOT_FOUND;

    AvlTree();

    void print();

    void print(Node* node);

    void print2D();

    void print2D(Node* node, int space);

    void insert(int id, int age);

    Node* get(int id);

    void remove(int id);

    Node* remove(Node* curNode, int id);

    int search(int id);
};