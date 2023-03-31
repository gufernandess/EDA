#include <iostream>
#include <sstream>
#include <string>
#include <climits>

#include "Tree.h"

using namespace std;

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


Tree::Tree(string serial) {
    _root = nullptr;
    stringstream ss(serial);
    _serializeTree(ss, &_root);
}

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

Tree::~Tree() {
    _clear(_root);
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


/* 
Para fazer essa função, suponha que as árvores dos testes nunca serão vazias, assim,
sempre haverá um menor valor de chave a ser retornado.
*/

int Tree::min_key() {
    _min_key(_root);
}


// Supõe que o ponteiro recebido sempre é diferente de nullptr

/**
 * É usado o INT_MAX para representar o maior inteiro possível, assim, se a árvore
 * for vazia, o menor valor de chave será o maior inteiro possível.
 * 
 * Além disso, o INT_MAX é um valor que nunca será retornado, pois a chave de um nó
 * sempre será menor que INT_MAX, que é usado como valor inicial do menor valor de chave.
 * 
 * Também é utilizado a função min() do C++, que retorna o menor valor entre dois inteiros.
*/

int Tree::_min_key(Node *node) {
    if(!node) {
        return INT_MAX;
    }

    return min(node->key, min(_min_key(node->left), _min_key(node->right)));
}

int Tree::sum_keys() {
    _sum_keys(_root);
}

int Tree::_sum_keys(Node *node) {
    return node == nullptr ? 0 : node->key + _sum_keys(node->left) + _sum_keys(node->right);
}

int Tree::total_internal_nodes() {
    _total_internal_nodes(_root);
}

/**
 * Se o nó for nulo ou for uma folha, então não é um nó interno, logo, retorna 0.
*/
    
int Tree::_total_internal_nodes(Node *node) {
    if(node == nullptr || (node->left == nullptr && node->right == nullptr)) {
        return 0;
    }

    return 1 + _total_internal_nodes(node->left) + _total_internal_nodes(node->right);
}

int Tree::um_filho() {
    _um_filho(_root);
}

/**
 * Se o nó for nulo, então não tem nenhum filho, logo, retorna 0. Caso contrário,
 * é verificado se o nó tem apenas um filho com uma disjunção exclusiva que
 * retorna 1 se apenas um dos operandos for verdadeiro, e 0 caso contrário.
 * */

int Tree::_um_filho(Node *node) {
    return (node == nullptr) ? 0 :
           ((node->left == nullptr) ^ (node->right == nullptr)) + 
           _um_filho(node->left) + _um_filho(node->right);
}