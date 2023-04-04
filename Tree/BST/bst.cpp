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
    if(node == nullptr || node->key == key) return node;

    node->key > key ? search(node->left, key) : search(node->right, key);

}

Node *BST::add(Node *node, int key) {
    if(node == nullptr) {
        node = new Node(key, nullptr, nullptr);

        return node;
    }

    if(node->key > key) {
        node->left = add(node->left, key);
    }

    else if(node->key < key) {
        node->right = add(node->right, key);
    }

    return node;
}

Node *BST::minimum(Node *node) {
    if(node == nullptr || node->left == nullptr) {
        return node;
    }

    return minimum(node->left);
}

Node *BST::maximum(Node *node) {
     if(node == nullptr || node->right == nullptr) {
        return node;
    }

    return minimum(node->right);
}

Node *BST::sucessor(Node *node, Node *root) {
    if(node == nullptr || root == nullptr) {
        return nullptr;
    }

    else if(node->right != nullptr) {
        return minimum(node->right);
    }

    else {
        return ancestral_sucessor(node, root);
    }
}

int BST::successor(int key) {
    Node *temp = search(root, key);

    if(temp != nullptr) {
        Node *succ = sucessor(temp, root);

        if(succ != nullptr) {
            return succ->key;
        }

        else {
            throw "Não existe sucessor";
        }
    }

    else throw "Não existe nó com essa chave";
}

int BST::maximum() {
    return maximum(root)->key;
} 

int BST::minimum() {
    return minimum(root)->key;
} 

void BST::add(int key) {
    root = add(root, key);
}


bool BST::contains(int key) {
    return search(root, key) != nullptr;
}