#ifndef TREE_H
#define TREE_H

#include <string>
#include <sstream>

using namespace std;

struct Node;

class Tree {
public:
    Tree(string serial);
    void inorder();   // Percurso em ordem simétrica
    void bshow();     // Exibe a árvore de forma amigável
    int size();
    int height();
    ~Tree();

private:
    Node *_root;
    Node *_clear(Node *root);
    void _inorder(Node *node);
    void _bshow(Node *node, string heranca);
    void _serializeTree(stringstream& ss, Node **node);
    int _size(Node *node);
    int _height(Node *node);
};

#endif