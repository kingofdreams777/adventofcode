#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using std::cout;
using std::endl;

int main() {
    int result = 0;
    int secondMost = 0;
    int thirdMost = 0;
    std::ifstream file("inputs/input.txt");
    if (!file.is_open()) {
        cout << "File not found" << endl;
        return 1;
    }

    int localMax = 0;
    int intermediate = 0;
    std::string line;
    while (std::getline(file, line)) {
    if (line.empty()) {
        intermediate = std::max(intermediate, localMax);
        if (intermediate > result) {
            thirdMost = std::max(thirdMost, secondMost);
            secondMost = std::max(secondMost, result);
            result = intermediate;
        }
        if (intermediate > secondMost && intermediate < result) {
            thirdMost = std::max(thirdMost, secondMost);
            secondMost = intermediate;
        }
        if (intermediate > thirdMost && intermediate < secondMost) {
            thirdMost = intermediate;
        }
        cout << "localMax: " << localMax << endl;
        localMax = 0;
        intermediate = 0;
        continue;
      }
      int num;
      std::istringstream iss(line);
      if (iss >> num) {
        localMax += num;
      } else {
        std::cerr << "Invalid input" << endl;
      }
    }

    file.close();

    cout << "Most: " << result << endl;
    cout << "Second: " << secondMost << endl;
    cout << "Third: " << thirdMost << endl;

    cout << "Total between the three: " << result + secondMost + thirdMost << endl;

    return 0;
}
