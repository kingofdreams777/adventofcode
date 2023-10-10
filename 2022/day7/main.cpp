#include <iostream>
#include <fstream>
#include <vector>
#include "FileNode.h"

using namespace std;

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cerr << "File ain't open beeotch";
    }

    int result = 0;
    string line;

    FileNode::FileNode root;


    file.close();
    return 0;
}
