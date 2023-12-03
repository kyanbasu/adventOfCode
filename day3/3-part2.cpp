#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct gear{
    int row, col, num;
};

vector<gear> gears;

int get_gear(int row, int col){
    for(gear g : gears){
        if(g.row == row && g.col == col) return g.num;
    }
    return 0;
}

int main(){
    ifstream f("input.txt");
    string line;
    vector<string> lines;

    int i;
    while(getline(f, line)){
        lines.push_back(line);
        i++;
    }
    line.clear();
    f.close();

    unsigned int sum = 0;
    for (int i = 0; i < lines.size(); i++)
    {
        int num = 0;
        int num_len = 0;
        for(int j = 0; j < lines[i].length(); j++){
            //cout << lines[i][j];
            if(isdigit(lines[i][j])){
                num = num*10+(lines[i][j]-'0');
                num_len++;
            }
            if(num != 0 && (!isdigit(lines[i][j]) || j+1 == lines[i].length())){
                if(isdigit(lines[i][j]) && j+1 == lines[i].length()) num_len--; //idfk
                for (int k = 0; k < num_len+2; k++)
                {
                    if(i != 0 && lines[i-1][j-num_len+k-1] == '*') {
                        int g = get_gear(i-1, j-num_len+k-1);
                        if(g == 0)
                            gears.push_back({i-1, j-num_len+k-1, num});
                        else
                            sum += (num * g);
                    }
                    if(i+1 != lines.size() && lines[i+1][j-num_len+k-1] == '*') {
                        int g = get_gear(i+1, j-num_len+k-1);
                        if(g == 0)
                            gears.push_back({i+1, j-num_len+k-1, num});
                        else
                            sum += (num * g);
                    }
                }
                if(j-num_len-1 >= 0 && lines[i][j-num_len-1] == '*'){
                        int g = get_gear(i, j-num_len-1);
                        if(g == 0)
                            gears.push_back({i, j-num_len-1, num});
                        else
                            sum += (num * g);
                    }
                if(j <= lines[i].length() && lines[i][j] == '*'){
                        int g = get_gear(i, j);
                        if(g == 0)
                            gears.push_back({i, j, num});
                        else
                            sum += (num * g);
                    }

                num = 0;
                num_len = 0;
            }
        }
    }
    cout << sum << '\n';

    return 0;
}