//
// Created by Gustavo Fernandes on 22/03/2023.
//

#ifndef EDA_TREE_H
#define EDA_TREE_H
#include <iostream>
#include "Node.h"

class Tree {
private:
    Node *root; // Ponteiro para a raiz da árvore

public:
    Tree(); // Cria uma árvore vazia
    Tree(int key, Tree& left_tree, Tree& right_tree); // Cria uma árvore com um valor, cujos filhos serão raízes de outras árvores

    // Funções para percorrer a árvore: pré-ordem, ordem simétrica e pós-ordem

    void preorder();
    void inorder();
    void posorder();
};

#endif //EDA_TREE_H
