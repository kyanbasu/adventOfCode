#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int part1(){
    ifstream f("input.txt");
    string line;
    
    int sum = 0;

    getline(f, line);
    int cur_value = 0;
    for (int i = 0, hash = 0; i < line.length(); i++)
    {
        if(line[i] == ','){
            sum += cur_value;
            cur_value = 0;
        } else {
            hash = 0 + line[i];
            cur_value += hash;
            cur_value = cur_value * 17;
            cur_value = cur_value % 256;
            if(i == line.length() - 1) sum += cur_value;
        }
    }
    
    
    return sum;
}

struct lens{
    string label;
    int power;
};

struct box{
    vector<lens> content;
};

int getHash(string s){
    int hash = 0;
    for (int i = 0; i < s.length(); i++)
    {
        hash += 0 + s[i];
        hash = hash * 17;
        hash = hash % 256;
    }
    return hash;
}

int part2(){
    ifstream f("input.txt");
    string line;
    
    vector<box> boxes(256);
    int sum = 0;

    getline(f, line);
    string cur_lens;
    for (int i = 0; i < line.length(); i++)
    {
        if(line[i] == ',' || i == 0){
            if(i!=0) i++;
            if(line.find('-', i) < line.find(',', i)){
                cur_lens = line.substr(i, line.find('-', i) - i);
                int hash = getHash(cur_lens);
                for(int j = 0; j < boxes[hash].content.size(); j++){
                    if(boxes[hash].content[j].label == cur_lens){
                        boxes[hash].content.erase(boxes[hash].content.begin() + j);
                        break;
                    }
                }
            }
            else {
                cur_lens = line.substr(i, line.find('=', i) - i);
                int hash = getHash(cur_lens);
                int power = line[line.find('=', i) + 1] - '0';
                bool exist = false;
                for(lens &content : boxes[hash].content){
                    if(content.label == cur_lens){
                        content.power = power;
                        exist = true;
                        break;
                    }
                }
                if(!exist) boxes[hash].content.push_back({cur_lens, power});
            }
        }
    }
    
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < boxes[i].content.size(); j++)
        {
            sum += (i+1) * (j+1) * boxes[i].content[j].power;
        }
    }
    
    
    
    return sum;
}

int main(){
    int p = part2();
    cout << p << '\n';
    
    return 0;
}