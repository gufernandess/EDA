#include <iostream>
#include "node.h"
#include "avl.h"
using namespace std;

int avl_tree::height(Node *node) {
    return (node == nullptr) ? 0 : node->height;
}

int avl_tree::balance(Node *node) {
    return height(node->right) - height(node->left);
}

Node* avl_tree::rightRotation(Node *p) {
    Node *u = p->left;

    p->left = u->right;
    u->right = p;

    p->height = 1 + max(height(p->left),height(p->right));
    u->height = 1 + max(height(u->left),height(u->right));

    return u;
}

Node* avl_tree::leftRotation(Node *p) {
    Node *u = p->right;

    p->right = u->left;
    u->left = p;

    p->height = 1 + max(height(p->right),height(p->left));
    u->height = 1 + max(height(u->left),height(u->right));
    return u;
}

void avl_tree::add(int key) {
    root = add(root, key);
}

Node* avl_tree::add(Node *p, int key) {
    if(p == nullptr) return new Node(key);
    if(key == p->key) return p;
    if(key < p->key) p->left = add(p->left, key);
    else p->right = add(p->right, key);
    
    p = fixup_node(p, key);

    return p;
}

Node* avl_tree::fixup_node(Node *p, int key) {
    p->height = 1 + max(height(p->left),height(p->right));

    int bal = balance(p);

    if(bal >= -1 && bal <= 1) return p;

    if(bal < -1 && key < p->left->key) p = rightRotation(p);

    else if(bal < -1 && key > p->left->key) {
        p->left = leftRotation(p->left);
        p = rightRotation(p);
    }
    else if(bal > 1 && key > p->right->key) p = leftRotation(p);

    else if(bal > 1 && key < p->right->key) {
        p->right = rightRotation(p->right);
        p = leftRotation(p);
    }

    return p;
}

void avl_tree::clear() {
    root = clear(root);
}

Node *avl_tree::clear(Node *node) {
    if(node != nullptr) {
        node->left = clear(node->left);
        node->right = clear(node->right);
        delete node;
    }

    return nullptr;
}

avl_tree::~avl_tree() {
    clear();
}

void avl_tree::bshow() const {
    bshow(root, "");
}

void avl_tree::bshow(Node *node, std::string heranca) const {
    if(node != nullptr && (node->left != nullptr || node->right != nullptr))
        bshow(node->right , heranca + "r");
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
        bshow(node->left, heranca + "l");
}

void avl_tree::remove(int key) {
    root = remove(root, key);
}

Node* avl_tree::remove(Node *node, int key) {
    if(node == nullptr) return nullptr;
    if(key < node->key) node->left = remove(node->left, key);
    else if(key > node->key) node->right = remove(node->right, key);

    else if(node->right == nullptr) {
        Node *child = node->left;
        delete node;

        return child;
    }
    else node->right = remove_successor(node, node->right);
    
    node = fixup_deletion(node); 
    
    return node;
}

Node* avl_tree::remove_successor(Node *root, Node *node) {
    if(node->left != nullptr) {
        node->left = remove_successor(root, node->left);
    }

    else {
        root->key = node->key;
        Node *aux = node->right;

        delete node;

        return aux;
    }

    node = fixup_deletion(node);

    return node;
}

Node* avl_tree::fixup_deletion(Node *node) {
    node->height = 1 + max(height(node->left),height(node->right));

    int bal = balance(node);

    if(bal > 1 && balance(node->right) >= 0) {
        return leftRotation(node);
    }
    else if(bal > 1 && balance(node->right) < 0) {
        node->right = rightRotation(node->right);
        return leftRotation(node);
    }
    else if(bal < -1 && balance(node->left) <= 0) {
        return rightRotation(node);
    }
    else if(bal < -1 && balance(node->left) > 0) { 
        node->left = leftRotation(node->left);
        return rightRotation(node);
    }
    return node;
}

Node* clone_rec(Node *node) {
    if(node == nullptr) return nullptr;

    Node *aux = new Node(node->key);

    aux->left = clone_rec(node->left);
    aux->left = clone_rec(node->right);

    return aux;
}

avl_tree::avl_tree(const avl_tree& t) {
    this->root = clone_rec(t.root);
}

avl_tree& avl_tree::operator=(const avl_tree& t) {
    if(this != &t) {
        clear();
        this->root = clone_rec(t.root);
    }

    return *this;
}

void inorder_rec(Node *node, void (*f)(int& key)) {
    if(node != nullptr) {
        inorder_rec(node->left, f);
        f(node->key);
        inorder_rec(node->right, f);
    }
}

void avl_tree::acces_keys_inorder(void (*f)(int& key)) {
    inorder_rec(root, f);
}

void inorder_rec(Node *node, std::vector<int>& v) {
    if(node != nullptr) {
        inorder_rec(node->left, v);
        v.push_back(node->key);
        inorder_rec(node->right, v);
    }
}

void avl_tree::key_as_vector(std::vector<int>& v) const {
    inorder_rec(root, v);
}