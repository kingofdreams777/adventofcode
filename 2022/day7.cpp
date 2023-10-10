//
// Created by ross on 10/5/23.
//

#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include "File.h"
#include "Directory.h"
using namespace std;

int main() {
    ifstream file("inputs/input7.txt");
    if (!file.is_open()) {
        cerr << "No file found" << endl;
    }

    File test("meow", 2);

    cout << test.getName() << endl;

    file.close();
    return 0;
}