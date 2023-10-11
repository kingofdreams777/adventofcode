//
// Created by ross on 10/10/23.
//

#ifndef DAY7_FILETREE_H
#define DAY7_FILETREE_H

#include <iostream>
#include <vector>

using namespace std;

namespace FileTree {

    class FileNode;

    class DirectoryNode {
    private:
        string _name;
        int _value;
        vector<FileNode*> _fileChildren;
        vector<DirectoryNode*> _directoryChildren;
        DirectoryNode* _parent;
    public:
        DirectoryNode(string name, DirectoryNode* parent);
        string getName();
        int getValue();
        void setValue(int value);
        void addFileChildren(FileNode* child);
        void addDirectoryChildren(DirectoryNode* child);
        vector<FileNode*> getFileChildren();
        vector<DirectoryNode*> getDirectoryChildren();
        void sumChildValues();
    };

    class FileNode {
    private:
        string _name;
        int _value;
        DirectoryNode* _parent;
    public:
        FileNode(string name, int value, DirectoryNode* parent);
        string getName();
        int getValue();
    };

} // FileTree

#endif //DAY7_FILETREE_H
