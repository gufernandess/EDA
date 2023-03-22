//
// Created by Gustavo Fernandes on 22/03/2023.
//

#include <iostream>
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
        preorder_aux(node->left);
        cout << node->key << " ";
        preorder_aux(node->right);
    }
}

void posorder_aux(Node* node) {
    if(node != nullptr) {
        posorder_aux(node->left);
        posorder_aux(node->right);
        cout << node->key << " ";
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
