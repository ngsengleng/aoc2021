#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using std::ifstream;
using std::string;
using std::vector;
using std::stringstream;
using std::cout;
using std::endl;
using std::getline;


void part1(vector<string> commands) { 
    int horizontal = 0;
    int vertical = 0;
    for (int i = 0; i < commands.size(); i++) {
        stringstream tokens(commands[i]);
        string token;
        bool isDirection = true;
        string direction;
        int steps;

        while (getline(tokens, token, ' ')) {
            if (isDirection) {
                isDirection = false;
                direction = token;
            } else {
                steps = stoi(token);
            }
        }

        if (direction == "forward") {
            horizontal += steps;
        } else if (direction == "down") {
            vertical += steps;
        } else {
            vertical -= steps;
        }
    }
    cout << horizontal * vertical << endl;
}

void part2(vector<string> commands) { 
    int horizontal = 0;
    int vertical = 0;
    int aim = 0;
    for (int i = 0; i < commands.size(); i++) {
        stringstream tokens(commands[i]);
        string token;
        bool isDirection = true;
        string direction;
        int steps;

        while (getline(tokens, token, ' ')) {
            if (isDirection) {
                isDirection = false;
                direction = token;
            } else {
                steps = stoi(token);
            }
        }
        
        if (direction == "forward") {
            horizontal += steps;
            vertical += steps * aim;
        } else if (direction == "down") {
            aim += steps;
        } else {
            aim -= steps;
        }
    }
    cout << horizontal * vertical << endl;
}

int main() {
    ifstream fh("day2.txt");
    string command;
    vector<string> commands;

    while (getline(fh, command)) {
        commands.push_back(command);
    }

    part1(commands);
    part2(commands);
}

