#include <iostream>
#include <sstream>
#include <string>
#include <stack>
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

int Tree::size() {
    return _size_iterativo(_root);
}

/**
 * É utilizada uma pilha para armazenar os nós, onde o tamanho da pilha é incrementado a cada nó visitado.
 * 
 * A cada iteração do laço, o nó do topo da pilha é removido e seus filhos são
 * adicionados na pilha, caso existam.
 * 
 * Dessa forma, a variável size é incrementada a cada nó visitado.
*/

int Tree::_size_iterativo(Node *node) {
    if(node == nullptr) {
        return 0;
    }

    int size;
    std::stack<Node*> stack;
    stack.push(node);

    for(size = 0; !stack.empty(); size++) {
        Node *node = stack.top();
        stack.pop();

        if(node->left != nullptr) {
            stack.push(node->left);
        }

        if(node->right != nullptr) {
            stack.push(node->right);
        }
    }

    return size;
}