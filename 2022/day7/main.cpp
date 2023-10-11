#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream file("./input.txt");
    if (!file.is_open()) {
        cerr << "File ain't open beeotch";
    }

    int result = 0;
    string line;

    while (getline(file, line))

    file.close();
    return 0;
}
