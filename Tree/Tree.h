//
// Created by Gustavo Fernandes on 22/03/2023.
//

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "Node.h"

class Tree {
private:
    Node *root; // Ponteiro para a raiz da árvore
    int size;

public:

    Tree();                                           // Cria uma árvore vazia
    Tree(int key, Tree& left_tree, Tree& right_tree); // Cria uma árvore com um valor, cujos filhos serão raízes de outras árvores

    ~Tree();                                          // Destrutor

    Tree(const Tree& tree) = delete; // Construtor de cópia

    string serialize(); // Serializa a árvore em uma string

    // Funções para percorrer a árvore: pré-ordem, ordem simétrica e pós-ordem

    void preorder();
    void inorder();
    void posorder();

    bool empty(); // Retorna true se a árvore estiver vazia

    bool contain(int key); // Retorna true se a árvore contém a chave key

    void clear(); // Limpa a árvore

    int size(); // Retorna o número de nós da árvore
};

#endif //TREE_H
