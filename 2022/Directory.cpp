//
// Created by ross on 10/10/23.
//

#include "Directory.h"

void Directory::addChildren(string name, int value) {
    File child = File(name, value);
    this->_children.push_back(child);
}

int Directory::calculateChildrenTotal() {
    int result = 0;
    for (auto child : this->getChildren()) {
        result += child.getValue();
    }

    return result;
}

vector<File> Directory::getChildren() {
    return this->_children;
}

Directory::Directory(string name, int value) : File(name, value) {
}
