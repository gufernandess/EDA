#include <vector>

class dynamic_set {
    public:

    virtual void add(int key) = 0;  // O(log * n)
    virtual bool remove(int key) const = 0;  // O(log * n)
    virtual bool contains(int key) const = 0;   // O(log * n)
    virtual int minimum() const = 0;  // O(log * n)
    virtual void maximum() const = 0;  // O(log * n)
    virtual int successor(int key) const = 0;  // O(log * n)
    virtual int predecessor(int key) const = 0;  // O(log * n)
    virtual void acces_keys_inorder(void (*f)(int& key)) = 0;  // O(n)
    virtual void key_as_vector(std::vector<int>& v) const = 0;  // O(n)
    virtual bool empty() const = 0;  // O(1)
    virtual int size() const = 0;  // O(n)
    virtual void clear() = 0;  // O(n)
    virtual ~dynamic_set() = default;
};