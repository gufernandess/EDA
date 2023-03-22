//
// Created by Gustavo Fernandes on 22/03/2023.
//

#include <iostream>
#include "Tree.h"

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
    Tree tree_four(4, empty, empty);
    Tree tree_six(6, empty, empty);
    Tree tree_seven(7, empty, empty);
    Tree tree_five(5, tree_six, tree_seven);
    Tree tree_three(3, tree_four, tree_five);

    tree_three.preorder();
    cout << endl;

    return 0;
}
