//
// Created by ross on 10/10/23.
//

#include <iostream>
#include "FileNode.h"

using namespace std;

namespace FileNode {
    FileNode::FileNode() {
        _name = "";
    }

    FileNode::FileNode(string name, int value) {
        _name = name;
        _value = value;
    }

    FileNode::FileNode(string name, FileNode *parent) {
        _name = name;
        _parent = parent;
    }

    string FileNode::getName() {
        return _name;
    }

    void FileNode::setName(string name) {
        _name = name;
    }

    int FileNode::getValue() {
        return _value;
    }

    void FileNode::setValue(int value) {
        _value = value;
    }

    void FileNode::addChildren(string name, int value) {
        FileNode child(name, value);
        _children.push_back(child);
    }

    vector<FileNode> FileNode::getChildren() {
        return _children;
    }

    void FileNode::calculateChildrenTotal() {
        if (getChildren().empty()) {
            return;
        }

        int result = 0;
        for (FileNode child : _children) {
            result += child.getValue();
        }

        setValue(result);
    }



} // FileNode