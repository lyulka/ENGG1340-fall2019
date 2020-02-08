#pragma once

class Node {
    public:
    int id;
    int age;
    Node* leftChild;
    Node* rightChild;

    Node (int id, int age);
};

class BinarySearchTree {
    public:
    Node* root;
    static const int NOT_FOUND;

    BinarySearchTree();

    void print();

    void print(Node* node);

    void print2D();

    void print2D(Node* node, int space);

    void insert(int id, int age);

    Node* get(int id);

    void remove(int id);

    Node* remove(Node* curNode, int it);

    int search(int id);
};