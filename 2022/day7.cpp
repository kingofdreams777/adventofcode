//
<<<<<<< HEAD
// Created by ross on 10/5/23.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class TreeNode {
private:
    string _name;
    int _value;
    vector<TreeNode> _children;

public:
    TreeNode(string name, int value) {
        this->_name = name;
        this->_value = value;
    }

    TreeNode(string name,
             int value,
             vector<TreeNode> children) {
        this->_name = name;
        this->_value = value;
        this->_children = children;
    }

    string getName() {
        return this->_name;
    }

    int getValue() {
        return this->_value;
    }

    void addChildren(string name, int value) {
        TreeNode child = TreeNode(name, value);
        this->_children.push_back(child);
    }

    
};

int main() {
    ifstream file("inputs/input7.txt");
    if (!file.is_open()) {
        cerr << "No file found" << endl;
    }
}
=======
// Created by rossm on 10/4/2023.
//

int main() {
    return 0;
}
>>>>>>> 50af12b74e566e5f5a672941d0898d7254ac902e
