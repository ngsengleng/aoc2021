#include <fstream>
#include <vector>
#include <iostream>
#include <string>

using std::ifstream;
using std::vector;
using std::string;
using std::cout;
using std::stoi;
using std::endl;

void part1(vector<int> array) {
    
    int counter = 0;

    for (int i = 1; i < array.size(); i++) {
        if (array[i] - array[i - 1] > 0) {
            counter++;
        }
    }
    cout << counter << "\n";
}

void part2(vector<int> array) {
    int prevSum = array[0] + array[1] + array[2];
    int counter = 0;

    for (int i = 3; i < array.size(); i++) {
        int currSum = array[i] + array[i - 1] + array[i - 2];
        if (currSum - prevSum > 0) {
            counter++;
        }
        prevSum = currSum;
    }
    cout << counter << endl;
}
int main() {
    // file parsing
    ifstream fh("day1.txt");

    int x;
    vector<int> array;
    while (fh >> x) {
        array.push_back(x);
    }
    part1(array);
    part2(array);
    
}

