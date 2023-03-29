#include <iostream>
#include <string>

#include "Tree.cpp"

using namespace std;

int main() {
	string line;
    getline(cin, line);
    Tree bt(line);
    cout << bt.height() << " " << bt.size() << endl;

    return 0;
}