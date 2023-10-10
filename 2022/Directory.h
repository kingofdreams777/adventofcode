//
// Created by ross on 10/10/23.
//

#ifndef INC_2022_DIRECTORY_H
#define INC_2022_DIRECTORY_H

#include "File.h"
#include <vector>

using namespace std;


class Directory : public File {
private:
    vector<File> _children;
public:
    Directory(string name, int value);
    void addChildren(string name, int value);
    int calculateChildrenTotal();
    vector<File> getChildren();

};


#endif //INC_2022_DIRECTORY_H
