#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream f("input.txt");
    string line;
    unsigned int total_ids = 0;
    unsigned int game_id = 1;
    int sum;
    
    int total_cubes[] = {12, 13, 14};

    while(getline(f, line)){
        line = line.substr(line.find(": ")+1, line.length());
       // cout << line << '\n';

        int count = 0;
        int min_cubes[] = {0, 0, 0};
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

                if(color == "red" && min_cubes[0] < count) min_cubes[0] = count;
                else if(color == "green" && min_cubes[1] < count) min_cubes[1] = count;
                else if(color == "blue" && min_cubes[2] < count) min_cubes[2] = count;
                cout << count << color << impossible << '\n';
                cout << min_cubes[0] << min_cubes[1] << min_cubes[2]<< '\n';

                color = "";
                count = 0;
                status = 0;
            }
        }
        if(!impossible) total_ids += game_id;
        sum += min_cubes[0] * min_cubes[1] * min_cubes[2];

        game_id++;
    }
    cout << "total ids " << total_ids;
    cout << "\nsum of min cubes " << sum;
    return 0;
}