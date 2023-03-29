//
// Created by Gustavo Fernandes on 21/03/2023.
//

#ifndef NODE_H
#define NODE_H

struct Node {
    // Atributos de um nó

    int key;
    Node* left;
    Node* right;

    Node(int key, Node* left, Node* right) { // Construtor de um nó
        this->key = key;
        this->left = left;
        this->right = right;
    }
};

#endif //NODE_H
