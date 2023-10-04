//
// Created by ross on 10/2/23.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int createInt(const string& string1) {
    return stoi(string1);
}

vector<int> createRanges(int start, int end) {
    vector<int> result;

    result.push_back(start);
    result.push_back(end);

    return result;
}

vector<int> splitStringDash(const string& line) {
    vector<int> result;
    string delimiter = "-";

    string start = line.substr(0, line.find(delimiter));
    string end = line.substr(line.find(delimiter) + 1, line.length());

    return createRanges(createInt(start), createInt(end));
}

vector<string> splitStringComma(const string& line) {
    vector<string> result;
    string delimiter = ",";

    string start = line.substr(0, line.find(delimiter));
    string end = line.substr(line.find(delimiter) + 1, line.length());

    result.push_back(start);
    result.push_back(end);

    return result;
}

bool areSelfContained(const vector<int>& v1, const vector<int>& v2) {
    bool result = false;

    if (v1[0] <= v2[0] && v1[1] >= v2[1]) {
        result = true;
    }

    if (v2[0] <= v1[0] && v2[1] >= v1[1]) {
        result = true;
    }

    return result;
}

bool areOverlapping(const vector<int>& v1, const vector<int>& v2) {
    if (v1[0] <= v2[0] && v1[1] >= v2[1]) { // left contains right
        return true;
    }

    if (v2[0] <= v1[0] && v2[1] >= v1[1]) { // right contains left
        return true;
    }

    if (v1[0] <= v2[1] && v1[1] >= v2[0]) { // left overlaps right
        return true;
    }

    if (v2[0] <= v1[1] && v2[1] >= v1[0]) {
        return true;
    }

    return false;
}

int main() {
    ifstream file("inputs/input4.txt");
    if (!file.is_open()) {
        cerr << "File not found" << endl;
        return 1;
    }

    int result = 0;
    string line;

    while (getline(file, line)) {
        vector<string> split1 = splitStringComma(line);
        vector<int> left = splitStringDash(split1[0]);
        vector<int> right = splitStringDash(split1[1]);

/*
        if (areSelfContained(left, right)) {
            result++;
        }
*/
        if (areOverlapping(left, right)) {
            result++;
        }
    }

    cout << "Total of Self Contained: " << result << endl;
    return 0;
}