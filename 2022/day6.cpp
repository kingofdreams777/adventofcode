//
// Created by ross on 10/3/23.
//
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// sliding window
int findSequence(string line) {
    int window = 14;
    int result = 0;
    // need a substring with 4 unique characters
    // have to keep track of the 4 characters in each 4 substrings
    // also keep track of how many the window has been shifted
    // what's a good way to keep track of the 4 in the sub array?
    // brute force would be to iterate through 4 twice and then sort the array checking each. that could work
    // poor time optimization though
    for (int i = 0; i < line.size(); ++i) {
        string substring;
        for (int j = 0; j < window; ++j) {
            substring.push_back(line[i + j]);
        }

        string sanityCheck = substring;
        sort(substring.begin(), substring.end());
        bool isRepeat = false;
        for (int j = 1; j < substring.size(); ++j) {
            if (substring[j-1] == substring[j]) {
                isRepeat = true;
            }
        }

        if (!isRepeat) {
            break;
        } else {
            result++;
        }
    }
    return result + 14;
}

int main() {
    ifstream file("inputs/input6.txt");
    if (!file.is_open()) {
        cerr << "Failed to open file" << endl;
    }

    int result = 0;
    string line;

    while (getline(file, line)) {
        result = findSequence(line);
    }

    cout << "Length before sequence: " << result << endl;

    return 0;
}