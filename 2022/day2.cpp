//
// Created by ross on 10/1/23.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::ifstream;
using std::vector;
using std::string;
using std::cerr;

int calculateIndividualHandScore(char hand) {
    int score = 0;
    switch (hand) {
        case 'A':
            score = 1; //Rock
            break;
        case 'B':
            score = 2; //Paper
            break;
        case 'C':
            score = 3; //Scissors
            break;
        case 'X':
            score = 1; //Lose
            break;
        case 'Y':
            score = 2; //Draw
            break;
        case 'Z':
            score = 3; //Win
            break;
        default:
            cerr << "Invalid value for your hand";
            break;
    }

    return score;
}

int calculateNeededHeroHand(int villainScore, char outcome) {
    int hero = 0;

    switch (outcome) {
        case 'X':
            //Loss
            if (villainScore != 1) {
                hero = villainScore - 1;
            } else {
                hero = 3;
            }
            break;
        case 'Y':
            //Draw
            hero = villainScore;
            break;
        case 'Z':
            //Win
            if (villainScore != 3) {
                hero = villainScore + 1;
            } else {
                hero = 1;
            }
            break;
    }

    return hero;
}

int calculateWinLossOrTie(char villain, char hero) {
    int score;

    int villainScore = calculateIndividualHandScore(villain);
    int heroScore = calculateNeededHeroHand(villainScore, hero);

    if (villainScore == heroScore) {
        score = 3;
    } else if (heroScore == villainScore + 1 || heroScore == villainScore - 2) {
        score = 6;
    } else {
        score = 0;
    }

    return score + heroScore;
}

vector<char> getHands(string line) {
    vector<char> hands;
    for (int i = 0; i < line.size(); ++i) {
        if (line[i] == ' ') {
            continue;
        }
        hands.push_back(line[i]);
    }

    return hands;
}

int main(){
    std::ifstream file("inputs/input2.txt");
    if (!file.is_open()) {
        cout << "File not found" << endl;
        return 1;
    }

    int result = 0;
    int lines = 0;
    string line;

    while (std::getline(file, line)) {
        vector<char> hands = getHands(line);
        cout << "Villain: " << hands[0] << " Hero: " << hands[1];
        int score = calculateWinLossOrTie(hands[0], hands[1]);
        cout << " Score: " << score << endl;
        result += score;
        lines ++;
    }

    file.close();

    cout << "Total Score: " << result << endl;
    cout << "Total number of hands played: " << lines << endl;

    return 0;
}
