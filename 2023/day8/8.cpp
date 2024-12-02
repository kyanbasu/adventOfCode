#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

struct directions{
    string left, right;
};

map<string, directions> nodes;

vector<char> instr;

int part1(){
    ifstream f("input.txt");
    string line;
    getline(f, line);

    for (int i = 0; i < line.length(); i++)
    {
        instr.push_back(line[i]);
    }    

    getline(f, line); //skip blank
    while(getline(f, line)){
        //cout << line << '\n';
        nodes[line.substr(0,3)] = {line.substr(7,3), line.substr(12,3)};
    }

    int i = 0;
    string cur_node = "AAA";
    while(1){
        if(instr[i%instr.size()] == 'L'){
            cur_node = nodes[cur_node].left;
        } else {
            cur_node = nodes[cur_node].right;
        }
        //cout << instr[i%instr.size()] << cur_node << '\n';
        i++;
        if(cur_node == "ZZZ") return i;
    }
    
    return -1;
}

part2(){
    ifstream f("inputx3.txt");
    string line;
    getline(f, line);

    for (int i = 0; i < line.length(); i++)
    {
        instr.push_back(line[i]);
    }

    vector<pair<int,int>> first_n_loop_size;
    vector<string> nodes_ed_w_a;

    getline(f, line); //skip blank
    while(getline(f, line)){
        //cout << line << '\n';
        if(line.substr(2,1) == "A") {nodes_ed_w_a.push_back(line.substr(0,3));
            first_n_loop_size.push_back({0, 0});
            cout << line.substr(0,3) << '\n';
        }
        nodes[line.substr(0,3)] = {line.substr(7,3), line.substr(12,3)};
    }
/*
DVA
JQA
PTA
CRA
AAA
BGA
*/

    int j = 0;

    while(1){
        bool all_z = true;
        for (int i = 0; i < nodes_ed_w_a.size(); i++)
        {
            if(instr[j%instr.size()] == 'L'){
                nodes_ed_w_a[i] = nodes[nodes_ed_w_a[i]].left;
            } else {
                nodes_ed_w_a[i] = nodes[nodes_ed_w_a[i]].right;
            }
            if(nodes_ed_w_a[i][2] != 'Z') all_z = false;
            if(nodes_ed_w_a[i][2] == 'Z' && first_n_loop_size[i].first == 0) first_n_loop_size[i].first = j;
            else if(nodes_ed_w_a[i][2] == 'Z' && first_n_loop_size[i].second == 0) first_n_loop_size[i].second = j - first_n_loop_size[i].first;
            if(first_n_loop_size[i].second != 0){
                cout << nodes_ed_w_a[i] << " " << first_n_loop_size[i].first << " " << first_n_loop_size[i].second << '\n';
                return -1;
            }
            cout << i << " - " << instr[j%instr.size()] << ' ' << nodes_ed_w_a[i] << ' ' << all_z << '\n';
        }
        j++;
        if(all_z) return j;
    }

    /* long way
    while(1){
        bool all_z = true;
        for (int i = 0; i < nodes_ed_w_a.size(); i++)
        {
            if(instr[j%instr.size()] == 'L'){
                nodes_ed_w_a[i] = nodes[nodes_ed_w_a[i]].left;
            } else {
                nodes_ed_w_a[i] = nodes[nodes_ed_w_a[i]].right;
            }
            if(nodes_ed_w_a[i][2] != 'Z') all_z = false;
            cout << i << " - " << instr[j%instr.size()] << ' ' << nodes_ed_w_a[i] << ' ' << all_z << '\n';
        }
        j++;
        if(all_z) return j;
    }
    */
    
    return -1;
}

int main(){
    int p = part2();
    cout << p << '\n';
    
    return 0;
}