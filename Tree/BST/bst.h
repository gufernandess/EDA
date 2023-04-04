#ifndef BST_H
#define BST_H

#include <iostream>
#include "node.h"

class BST { 
public:
    BST() = default;                        // Construtor default
    BST(const BST& tree) = delete;             // Construtor de cópia removido
    BST& operator=(const BST& tree) = delete;  // Operador de atribuição removido
    ~BST();                                 // Destrutor
    void add(int key);                      // Adicionar chave 
    void remove(int key);                   // Remover chave
    bool contains(int key);                 // A árvore contém esta chave?
    int minimum();                          // Devolve chave mínima
    int maximum();                          // Devolve chave máxima
    int successor(int key);                   // Devolve chave sucessora de key
    int predecessor(int key);                 // Devolve chave antecessora de key
    void inorder();                         // Imprime as chaves em ordem simétrica

private:
    Node *root {nullptr};
    Node *add(Node *node, int key);
    Node *search(Node *node, int key);
    Node *clear(Node *node);
    Node *minimum(Node *node);
    Node *maximum(Node *node);
    Node *ancestral_sucessor(Node *x, Node *raiz);
    Node *ancestral_predecessor(Node *x, Node* raiz);
    Node *sucessor(Node *x, Node *raiz);
    Node *predecessor(Node *x, Node* raiz);
    Node *remove(int k, Node *node);
    Node *removeRoot(Node *node);
    void inorder(Node *node);
};

#endif
