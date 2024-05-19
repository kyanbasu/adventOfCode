#include <iostream>
#include <fstream>

using namespace std;

const string num_names[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(){
    ifstream f("input.txt");
    string line;
    int sum;
    while(getline(f, line)){
        int first = 0;
        int first_occ = INT_MAX;
        int last = 0;
        int last_occ = 0;
        
        for (int i = 0; i < line.length(); i++)
        {
            if(first == 0 && line[i] - '0' >= 1 && line[i] - '0' <= 9 ){
                first = line[i] - '0';
                first_occ = i;
            }
            if(last == 0 && line[line.length() - i-1] - '0' >= 1 && line[line.length() - i-1] - '0' <= 9 ){
                last = line[line.length() - i-1] - '0';
                last_occ = line.length() - i-1;
            }
        }

        for (int i = 0; i < 9; i++)
        {
            if(line.find(num_names[i]) != string::npos && first_occ > line.find(num_names[i])){
                first_occ = line.find(num_names[i]);
                first = i+1;
            }
            if(line.rfind(num_names[i]) != string::npos && last_occ < line.rfind(num_names[i])){
                last_occ = line.rfind(num_names[i]);
                last = i+1;
            }
        }
        //cout << first_occ << " " << last_occ << " - " << first << " " << last << '\n';

        sum += first*10+last;
    }
    cout << '\n' << sum << '\n';

    return 0;
}