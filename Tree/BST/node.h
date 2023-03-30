#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int key, Node *left, Node *right) {
        this->key = key;
        this->left = left;
        this->right = right;
    }

    ~Node() { // Destrutor
        cout << "removido: " << this->key << endl;
    }
};

#endif 
