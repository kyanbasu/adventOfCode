#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int part1(){
    ifstream f("inputx.txt");
    string line;
    
    int sum = 0;

    while(getline(f, line)){
        vector<vector<int>> lines(1);
        cout << line << '\n';
        istringstream is(line);
        int n;
        while(is >> n){
            cout << n << '\n';
            lines[0].push_back(n);
        }
    }
    
    return sum;
}

int main(){
    int p = part1();
    cout << p << '\n';
    
    return 0;
}