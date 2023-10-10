//
// Created by ross on 10/10/23.
//

#include "File.h"

File::File(std::string name, int value) {
    this->_name = name;
    this->_value = value;
}

string File::getName() {
    return this->_name;
}

int File::getValue() {
    return this->_value;
}