//
// Created by Gustavo Fernandes on 22/03/2023.
//

#include <iostream>
#include "Tree.cpp"

using namespace std;

int main() {

    /* Cria a árvore:

              3
            /   \
           4     5
               /   \
              6     7
    */

    Tree empty;
    Tree fourth_tree(4, empty, empty);
    Tree sixth_tree(6, empty, empty);
    Tree seventh_tree(7, empty, empty);
    Tree fifth_tree(5, sixth_tree, seventh_tree);
    Tree third_tree(3, fourth_tree, fifth_tree);

    third_tree.preorder();
    cout << endl;

    return 0;
}
