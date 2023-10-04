//
// Created by ross on 10/2/23.
//
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

stack<char> createStacks(string string1) {
    stack<char> result;
    reverse(string1.begin(), string1.end());

    for (char c : string1) {
        result.push(c);
    }

    return result;
}

class SupplyStacks {
private:
    stack<char> s1;
    stack<char> s2;
    stack<char> s3;
    stack<char> s4;
    stack<char> s5;
    stack<char> s6;
    stack<char> s7;
    stack<char> s8;
    stack<char> s9;


public:
    SupplyStacks(string str1,
                 string string2,
                 string string3,
                 string string4,
                 string string5,
                 string string6,
                 string string7,
                 string string8,
                 string string9) {
        this->s1 = createStacks(str1);
        this->s2 = createStacks(string2);
        this->s3 = createStacks(string3);
        this->s4 = createStacks(string4);
        this->s5 = createStacks(string5);
        this->s6 = createStacks(string6);
        this->s7 = createStacks(string7);
        this->s8 = createStacks(string8);
        this->s9 = createStacks(string9);
    }
    stack<char>* getStackByNumber(int num) {
        switch (num) {
            case 1:
                return &s1;
            case 2:
                return &s2;
            case 3:
                return &s3;
            case 4:
                return &s4;
            case 5:
                return &s5;
            case 6:
                return &s6;
            case 7:
                return &s7;
            case 8:
                return &s8;
            case 9:
                return &s9;
            default:
                cerr << "Invalid integer passed. Please between 1-9";
        }
    }
    void moveItems(int numOperations, int source, int destination) {
        stack<char> *sourceStack = getStackByNumber(source);
        stack<char> *destinationStack = getStackByNumber(destination);

        for (int i = 0; i < numOperations; ++i) {
            destinationStack->push(sourceStack->top());
            sourceStack->pop();
        }
    }

    void moveItemsPart2(int numOperations, int source, int destination) {
        stack<char> itemsToMove;

        stack<char> *sourceStack = getStackByNumber(source);
        stack<char> *destinationStack = getStackByNumber(destination);

        for (int i = 0; i < numOperations; ++i) {
            itemsToMove.push(sourceStack->top());
            sourceStack->pop();
        }

        for (int i = 0; i < numOperations; ++i) {
            destinationStack->push(itemsToMove.top());
            itemsToMove.pop();
        }
    }

    string getTopItemsFromAllStacks() {
        string result;

        for (int i = 1; i < 10; ++i) {
            stack<char> *currentStack = getStackByNumber(i);
            result.push_back(currentStack->top());
        }

        return result;
    }

    static vector<int> interpretInstructions(string str) {
        char delimiter = ' ';
        string next;
        vector<string> result;

        for (string::const_iterator it = str.begin(); it != str.end(); it++) {
            if (*it == delimiter) {
                if (!next.empty()) {
                    result.push_back(next);
                    next.clear();
                }
            } else {
                next += *it;
            }
        }

        if (!next.empty()) {
            result.push_back(next);
        }

        vector<int> numResults;

        for (const string& s : result) {
            int num;
            istringstream iss (s);
            if (iss >> num) {
                numResults.push_back(stoi(s));
            }
        }

        return numResults;
    }
};


int main() {
    SupplyStacks solution(
            "VCWLRMFQ",
            "LQD",
            "BNCWGRSP",
            "GQBHDCL",
            "SZFLGV",
            "PNGD",
            "WCFVPZD",
            "SMDPC",
            "CPMVTWNZ"
            );

    ifstream file("inputs/input5.txt");
    if (!file.is_open()) {
        cerr << "Failed to open file" << endl;
    }

    string result;
    string line;

    while (getline(file, line)) {
        vector<int> instructions = solution.interpretInstructions(line);
        solution.moveItemsPart2(instructions[0], instructions[1], instructions[2]);
    }

    result = solution.getTopItemsFromAllStacks();

    cout << "Top Items from all stacks: " << result << endl;

    return 0;
}
