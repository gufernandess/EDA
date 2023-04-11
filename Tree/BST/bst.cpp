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

Node *BST::predecessor(Node *key, Node* root) {
    if(key == nullptr || root == nullptr) {
        return nullptr;
    }

    else if(key->left != nullptr) {
        return maximum(key->left);
    }

    else {
        return ancestral_predecessor(key, root);
    }
}

Node *BST::remove(int key, Node* node) {
    if(node == nullptr) {
        return nullptr;
    }

    if(node->key > key) {
        node->left = remove(key, node->left);
    }

    else if(node->key < key) {
        node->right = remove(key, node->right);
    }

    else {
        node = removeRoot(node);
    }

    return node;
}

Node *BST::removeRoot(Node *node) {
    if(node->left == nullptr && node->right == nullptr) {
        delete node;
        return nullptr;
    }

    else if(node->left == nullptr) {
        Node *temp = node->right;
        delete node;
        return temp;
    }

    else if(node->right == nullptr) {
        Node *temp = node->left;
        delete node;
        return temp;
    }

    else {
        Node *temp = minimum(node->right);
        node->key = temp->key;
        node->right = remove(temp->key, node->right);
        return node;
    }
}

void BST::remove(int key) {
    root = remove(key, root);
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


int BST::predecessor(int key) {
    Node *temp = search(root, key);

    if(temp != nullptr) {
        Node *pred = predecessor(temp, root);

        if(pred != nullptr) {
            return pred->key;
        }

        else {
            throw "Não existe predecessor";
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