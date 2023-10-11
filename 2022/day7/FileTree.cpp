//
// Created by ross on 10/10/23.
//

#include "FileTree.h"

namespace FileTree {
    DirectoryNode::DirectoryNode(string name, DirectoryNode *parent) {
        _name = name;
        _parent = parent;
    }

    string DirectoryNode::getName() {
        return _name;
    }

    int DirectoryNode::getValue() {
        return _value;
    }

    void DirectoryNode::setValue(int value) {
        _value = value;
    }

    void DirectoryNode::addFileChildren(FileNode *child) {
        _fileChildren.push_back(child);
    }

    void DirectoryNode::addDirectoryChildren(DirectoryNode *child) {
        _directoryChildren.push_back(child);
    }

    vector<FileNode *> DirectoryNode::getFileChildren() {
        return _fileChildren;
    }

    vector<DirectoryNode *> DirectoryNode::getDirectoryChildren() {
        return _directoryChildren;
    }

    void DirectoryNode::sumChildValues() {
        int result = 0;
        for (:) {

        }
    }


} // FileTree