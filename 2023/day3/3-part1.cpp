#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

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
    bool do_add = false;
    const string chars = "@#$%&*+-=/";
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
                    if(i != 0 && chars.find(lines[i-1][j-num_len+k-1]) != string::npos) do_add = true;
                    if(i+1 != lines.size() && chars.find(lines[i+1][j-num_len+k-1]) != string::npos) do_add = true;
                }
                if(j-num_len-1 >= 0 && chars.find(lines[i][j-num_len-1]) != string::npos) do_add = true;
                if(j <= lines[i].length() && chars.find(lines[i][j]) != string::npos) do_add = true;
                cout << num << '-' << do_add << lines[i][j-num_len-1] << '\n';
                if(do_add) sum += num;

                num = 0;
                num_len = 0;
                do_add = false;
            }
        }
        //cout << '\n';
    }
    cout << sum << '\n';

    return 0;
}