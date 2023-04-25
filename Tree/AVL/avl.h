#ifndef AVL_H
#define AVL_H
#include <string>
#include "node.h"
#include "dynamic_set.h"

class avl_tree : public dynamic_set {
public:
    avl_tree() = default;
    avl_tree(const avl_tree& t);

    avl_tree& operator=(const avl_tree& t);
    void add(int key);
    void bshow() const;
    void clear();
    void remove(int key);
    ~avl_tree();

    virtual void add(int key);  // O(log * n)
    virtual bool remove(int key) const;  // O(log * n)
    virtual bool contains(int key) const;
    virtual int minimum() const;  // O(log * n)
    virtual void maximum() const;  // O(log * n)
    virtual int successor(int key) const;  // O(log * n)
    virtual int predecessor(int key) const;  // O(log * n)
    virtual void acces_keys_inorder(void (*f)(int& key));  // O(n)
    virtual void key_as_vector(std::vector<int>& v) const;  // O(n)
    virtual bool empty() const;  // O(1)
    virtual int size() const;  // O(n)
    virtual void clear();  // O(n)
    
private:
    Node *root {nullptr};

    int height(Node *node);
    int balance(Node *node);
    Node* rightRotation(Node *p);
    Node* leftRotation(Node *p);
    Node* add(Node *p, int key);
    Node* fixup_node(Node *p, int key);
    void bshow(Node *node, std::string heranca) const;
    Node* clear(Node *node);
    Node* remove(Node *node, int key); 
    Node* remove_successor(Node *root, Node *node);
    Node* fixup_deletion(Node *node);
};

#endif