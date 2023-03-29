//
// Created by Gustavo Fernandes on 22/03/2023.
//

#include <iostream>
#include <sstream>
#include <string>

#include "Tree.h"

using namespace std;

void preorder_aux(Node* node) {
    if(node != nullptr) {
        cout << node->key << " ";
        preorder_aux(node->left);
        preorder_aux(node->right);
    }
}

void inorder_aux(Node* node) {
    if(node != nullptr) {
        inorder_aux(node->left);
        cout << node->key << " ";
        inorder_aux(node->right);
    }
}

void posorder_aux(Node* node) {
    if(node != nullptr) {
        posorder_aux(node->left);
        posorder_aux(node->right);
        cout << node->key << " ";
    }
}

bool contain_aux(Node *node, int key) {
    if(node == nullptr) {
        return false;
    } else {
        if(node->key == key) {
            return true;
        } else {
            return contain_aux(node->left, key) || contain_aux(node->right, key);
        }
    }
}

Node *clear_aux(Node *node) {
    if(node == nullptr) {
        return nullptr;
    } else {
        node->left = clear_aux(node->left);
        node->right = clear_aux(node->right);

        delete node;
    }
}

int size_aux(Node *node) {
    return node == nullptr ? 0 : 1 + size_aux(node->left) + size_aux(node->right);
}

void serialize_aux(Node *node, stringstream& ss) { // Serialização pré-ordem
    if(node == nullptr) {
        ss << "# ";
    } else {
        ss << node->key << " ";
        serialize_aux(node->left, ss);
        serialize_aux(node->right, ss);
    }
}

void Tree::preorder() {
    preorder_aux(root);
}
void Tree::inorder() {
    inorder_aux(root);
}
void Tree::posorder() {
    posorder_aux(root);
}

Tree::Tree() {
    root = nullptr;
}


Tree::Tree(int key, Tree& left_tree, Tree& right_tree) {
    root = new Node(key, left_tree.root, right_tree.root); // Criando um novo nó, cujos filhos são outras raízes
    
    left_tree.root = nullptr;
    right_tree.root = nullptr;
}

bool Tree::empty() {
    return root == nullptr;
}

bool Tree::contain(int key) {
    return contain_aux(root, key);
}

void Tree::clear() {
    root = clear_aux(root);
}

int Tree::size() {
    return size_aux(root);
}

Tree::~Tree() {
    clear();
}

string Tree::serialize() {
    stringstream ss;
    serialize_aux(root, ss);
    return ss.str();
}
