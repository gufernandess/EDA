#include <iostream>
#include <sstream>
#include <string>
#include "Tree.h"

struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int k, Node *l = nullptr, Node *r = nullptr) {
        this->key = k;
        this->left = l;
        this->right = r;
    }
};

Tree::Tree() {
    _root = nullptr;
}

Tree::Tree(std::string serial) {
    _root = nullptr;
    std::stringstream ss(serial);
    _serializeTree(ss, &_root);
}

Tree::~Tree() {
    _root = _clear(_root);
}

void Tree::_serializeTree(std::stringstream& ss, Node **node) {
    std::string value;
    ss >> value;
    if(value == "#") // filho == nullptr
        return;
    int key = std::stoi(value);
    *node = new Node(key);
    _serializeTree(ss, &((*node)->left));
    _serializeTree(ss, &((*node)->right));
}

Node *Tree::_clear(Node *node) {
    if(node != nullptr) { // caso geral: vamos liberar essa arvore
        node->left = _clear(node->left);
        node->right = _clear(node->right);
        delete node;
    }
    return nullptr;
}

void Tree::inorder() {
    _inorder(_root);
    std::cout << std::endl;
}

void Tree::_inorder(Node *node) {
    if(node != nullptr) { // Caso Geral
        _inorder(node->left);
        std::cout << node->key << " ";
        _inorder(node->right);  
    }
}

void Tree::bshow(){
    _bshow(_root, "");
}

void Tree::_bshow(Node *node, std::string heranca) {
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->right , heranca + "r");
    for(int i = 0; i < (int) heranca.size() - 1; i++)
        std::cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
    if(heranca != "")
        std::cout << (heranca.back() == 'r' ? "┌───" : "└───");
    if(node == nullptr){
        std::cout << "#" << std::endl;
        return;
    }
    std::cout << node->key << std::endl;
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->left, heranca + "l");
}


bool Tree::identical(Tree *tree) {
    _identical(this->_root, tree->_root);
}

/**
 * O retorno é uma conjunção de duas condições:
 * 
 * 1. O nó a esquerda do primeiro é igual ao nó a esquerda do segundo;
 * 2. O nó a direita do primeiro é igual ao nó a direita do segundo;
 * 
 * Assim, recursivamente, se a esquerda e a direita forem iguais, então a árvore é igual.
*/

bool Tree::_identical(Node *firstNode, Node *secondNode) {
    if(firstNode == nullptr && secondNode == nullptr) {
        return true;
    }

    if((firstNode == nullptr || secondNode == nullptr) || (firstNode->key != secondNode->key)) {
        return false;
    }

    return _identical(firstNode->left, secondNode->left) && _identical(firstNode->right, secondNode->right);

}

Tree *Tree::clone() {
    Tree *newTree = new Tree();
    newTree->_root = _clone(this->_root);

    return newTree;
}

/**
 * Cria-se um novo nó com a chave do nó atual e recursivamente faz-se a cópia dos nós da esquerda e da direita.
*/

Node *Tree::_clone(Node *node) {
    if(node == nullptr) {
        return nullptr;
    }

    Node* newNode = new Node(node->key);

    newNode->left = _clone(node->left);
    newNode->right = _clone(node->right);

    return newNode;
}