//
// Created by ross on 10/1/23.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int calculatePriority(char value) {
    if (value >= 'A' && value <= 'Z') {
        return value - 38;
    } else {
        return value - 96;
    }
}

vector<vector<char>> splitLine(string line) {
    vector<vector<char>> result;

    vector<char> v1 (line.begin(), line.begin() + line.size() / 2);
    vector<char> v2 (line.begin() + line.size() / 2, line.end());

    result.push_back(v1);
    result.push_back(v2);

    return result;
}

char findDuplicate(vector<char> v1, vector<char> v2, vector<char> v3) {
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    sort(v3.begin(), v3.end());
    vector<char> common(v1.size() + v2.size());
    vector<char> common2(v1.size() + v2.size() + v3.size());
    vector<char>::iterator it, st;

    it = set_intersection(v1.begin(),
                          v1.end(),
                          v2.begin(),
                          v2.end(),
                          common.begin());

    st = set_intersection(common.begin(),
                          common.end(),
                          v3.begin(),
                          v3.end(),
                          common2.begin());

    return common2[0];
}

int main() {
    ifstream file("inputs/input3.txt");
    if (!file.is_open()) {
        cerr << "File not found" << endl;
        return 1;
    }

    int result = 0;
    int lines = 0;
    string line;
    
    vector<char> v1,v2,v3;

    while (std::getline(file, line)) {
        switch (lines) {
            case 0:
                for (auto c : line) {
                    v1.push_back(c);
                }
                break;
            case 1:
                for (auto c : line) {
                    v2.push_back(c);
                }
                break;
            case 2:
                for (auto c : line) {
                    v3.push_back(c);
                }
                break;
            default:
                break;
        }
        if (lines == 2) {
            char dupe = findDuplicate(v1, v2, v3);
            result += calculatePriority(dupe);
            v1.clear();
            v2.clear();
            v3.clear();
            lines = 0;
        } else {
            lines++;
            continue;
        }
    }
    file.close();

    cout << "Total Sum of Priorities: " << result << endl;

    return 0;
}
