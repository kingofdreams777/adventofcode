//
// Created by ross on 10/10/23.
//

#ifndef DAY7_FILENODE_H
#define DAY7_FILENODE_H
#include <vector>

using namespace std;

namespace FileNode {

    class FileNode {
    private:
        string _name;
        int _value = 0;
        vector<FileNode> _children;
        FileNode *_parent = nullptr;

    public:
        FileNode();
        FileNode(string name, int value);
        FileNode(string name, FileNode *parent);
        string getName();
        void setName(string name);
        int getValue();
        void setValue(int value);
        void addChildren(string name, int value);
        vector<FileNode> getChildren();
        void calculateChildrenTotal();
    };

} // FileNode

#endif //DAY7_FILENODE_H
