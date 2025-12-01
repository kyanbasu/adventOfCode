#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cassert>

using namespace std;

struct Input {
    bool right;
    int clicks;
};

vector<Input> parse(string _in){
    vector<Input> out;
    
    ifstream file_in(_in);

    string line;
    while (getline(file_in, line))
    {
        Input in = {
            line.at(0) == 'R',
            stoi(line.substr(1))
        };
        out.push_back(in);
    }

    return out;
}

int part1(vector<Input> _in){
    int currentPos = 50;
    int totalZeros = 0;

    for(auto i : _in){
        if(i.right){
            currentPos += i.clicks;
        } else {
            currentPos -= i.clicks;
        }
        currentPos %= 100;
        if (currentPos == 0) totalZeros++;
    }

    return totalZeros;
}

int part2(vector<Input> _in){
int currentPos = 50;
    int totalZeros = 0;

    for(auto i : _in){
        for(int step = 0; step < i.clicks; step++) {
            
            if (i.right) {
                currentPos++;
            } else {
                currentPos--;
            }

            if (currentPos > 99) {
                currentPos = 0;
            }

            if (currentPos < 0) {
                currentPos = 99;
            }
            if (currentPos == 0) {
                totalZeros++;
            }
        }
    }

    return totalZeros;
}

int main(){
    auto inExample = parse("example.txt");
    auto input = parse("input.txt");

    int out1 = part1(inExample);
    cout << "Example 1 result is: " << out1 << "\n\n";
    assert((out1 == 3) && "Example result isn't correct");

    cout << "Part 1 result is: " << part1(input) << "\n\n";
    
    int out2 = part2(inExample);
    cout << "Example 2 result is: " << out2 << "\n\n";
    assert((out2 == 6) && "Example result isn't correct");

    cout << "Part 2 result is: " << part2(input) << "\n\n";
}