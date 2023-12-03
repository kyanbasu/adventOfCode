#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream f("input.txt");
    string line;
    unsigned int total_ids = 0;
    unsigned int game_id = 1;
    
    int total_cubes[] = {12, 13, 14};

    while(getline(f, line)){
        line = line.substr(line.find(": ")+1, line.length());
       // cout << line << '\n';

        int count;
        string color = "";
        int status = 0;
        bool impossible = false;
        int eol = 0;
        for(char& c : line){
            eol++;
            if(status == 1 && c != ' ') count = count*10 + c - '0';
            if(status == 2 && !(c == ',' || c == ';')) color += c;

            if(c == ' ') status++;
            if(c == ',' || c == ';' || eol == line.length()) {
                if(color == "red" && count > total_cubes[0]) impossible = true;
                else if(color == "green" && count > total_cubes[1]) impossible = true;
                else if(color == "blue" && count > total_cubes[2]) impossible = true;
                cout << count << color << impossible << '\n';

                color = "";
                count = 0;
                status = 0;
            }
        }
        if(!impossible) total_ids += game_id;

        game_id++;
    }
    cout << total_ids;
    return 0;
}