#include <iostream>
#include "bst.h"

using namespace std;

BST::BST() {
    root = nullptr;
}

BST::~BST() {
    root = clear(root);
}

Node *BST::clear(Node *node) {
    if(node != nullptr) {
        node->left = clear(node->left);
        node->right = clear(node->right);

        delete node;
    }

    return nullptr;
}

Node *BST::search(Node *node, int key) {
    if(node == nullptr || node->key == key) {
        return node;
    }

    if(node->key > key) {
        search(node->left, key);
    }

    else {
        search(node->right, key);
    }
}

bool BST::contains(int key) {
    return search(root, key) != nullptr;
}