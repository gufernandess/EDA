#include <iostream>
#include <sstream>
#include <string>
#include "Tree.h"

using namespace std;

// Definição do struct Node

/* Em C++ os structs podem ter funções-membro, como construtores, destrutores, etc. */

struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int key, Node *left = nullptr, Node *right = nullptr) {
        this->key = key;
        this->left = left;
        this->right = right;
    }
};

// Construtor
Tree::Tree(string serial) {
    _root = nullptr;
    stringstream ss(serial);
    _serializeTree(ss, &_root);
}

/* Essa função recursiva recebe como entrada uma string contendo uma versão serializada da árvore
   e recebe um ponteiro para ponteiro para o nó raiz.
*/

// A função lê os dados e constrói a árvore seguindo um percurso em pré-ordem.

void Tree::_serializeTree(stringstream& ss, Node **node) {
    string value;
    ss >> value;
    if(value == "#") // filho == nullptr
        return;
    int key = stoi(value);
    *node = new Node(key);
    _serializeTree(ss, &((*node)->left));
    _serializeTree(ss, &((*node)->right));
}

// Destrutor
Tree::~Tree() {
    _root = _clear(_root);
}

// Essa função recebe uma raiz chamada node e ela libera todos os nós decendentes de node e o próprio node.

Node *Tree::_clear(Node *node) {
    if(node != nullptr) { // caso geral: vamos liberar essa árvore
        node->left = _clear(node->left);
        node->right = _clear(node->right);

        delete node;
    }

    return nullptr;
}

void Tree::inorder() {
    _inorder(_root);
    cout << endl;
}

void Tree::_inorder(Node *node) {
    if(node != nullptr) { // Caso Geral
        _inorder(node->left);
        cout << node->key << " ";
        _inorder(node->right);  
    }
}

void Tree::bshow(){
    _bshow(_root, "");
}

void Tree::_bshow(Node *node, string heranca) {
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->right , heranca + "r");
    for(int i = 0; i < (int) heranca.size() - 1; i++)
        cout << (heranca[i] != heranca[i + 1] ? "│   " : "    ");
    if(heranca != "")
        cout << (heranca.back() == 'r' ? "┌───" : "└───");
    if(node == nullptr){
        cout << "#" << endl;
        return;
    }
    cout << node->key << endl;
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        _bshow(node->left, heranca + "l");
}

int Tree::size() {
    return _size(_root);
}

int Tree::_size(Node *node) {
    if(node == nullptr) {
        return 0;
    }

    return 1 + _size(node->left) + _size(node->right);
}

int Tree::height() {
    return _height(_root);
}

/**
 * A altura da árvore é obtida através da função max entre a altura da subárvore esquerda e a altura da subárvore direita.
*/

int Tree::_height(Node *node) {
    if(node == nullptr) {
        return 0;
    }

    return 1 + max(_height(node->left), _height(node->right));
}



