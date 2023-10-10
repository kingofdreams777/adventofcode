//
// Created by ross on 10/10/23.
//

#ifndef INC_2022_FILE_H
#define INC_2022_FILE_H

#include <iostream>
#include <fstream>

using namespace std;

class File {
private:
    string _name;
    int _value;

public:
    File(string name, int value);
    string getName();
    int getValue();
};


#endif //INC_2022_FILE_H
