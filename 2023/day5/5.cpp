#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define uint unsigned int

uint part1(){
    ifstream f("input.txt");
    string line;
    
    uint lowest = UINT_MAX;
    vector<uint> seeds(1);
    vector<bool> found_index(1);
    if(f.good()){
        //parse seeds to seek
        getline(f, line);
        line = line.substr(7, line.length()-7);
        for (int i = 0, j = 0; i < line.length(); i++)
        {
            if(isdigit(line[i]))
                seeds[j] = seeds[j]*10 + (line[i] - '0');
            else{
                j++;
                seeds.resize(j+1);
                found_index.resize(j+1);
            }
        }
    }
    int state = -1, before_state = 0;
    
    while(getline(f, line)){
        uint dest=0, source=0, range=0;
        if(isdigit(line[0])){
            if(before_state != state) {
                fill(found_index.begin(), found_index.end(), false); //cout << "Reset found index" << '\n';
            }
            //get destination, source and range
            for (int i = 0, j = 0; i < line.length(); i++)
            {
                if(isdigit(line[i]))
                    if(j==0)
                        dest = dest*10 + (line[i] - '0');
                    else if(j==1)
                        source = source*10 + (line[i] - '0');
                    else
                        range = range*10 + (line[i] - '0');
                else{
                    j++;
                }
            }

            //find seed in range
            for (int i = 0; i < seeds.size(); i++)
            {
                if(seeds[i] >= source && seeds[i] < source+range && !found_index[i]) {
                    seeds[i] = dest + seeds[i]-source;
                    found_index[i] = true;
                }
            }
            before_state = state;
        }
        else if(!line.empty()) state++;
    }
    //cout << seed << " - " << seeds << '\n';
    //cout << seeds[0] << '\n';
    for(uint seed : seeds){
        if(seed < lowest) lowest = seed;
    }
    return lowest;
}

uint part2(){
    ifstream f("input.txt");
    string line;
    
    uint lowest = UINT_MAX;
    vector<uint> seeds1(1);
    vector<bool> found_index(1);
    if(f.good()){
        //parse seeds to seek
        getline(f, line);
        line = line.substr(7, line.length()-7);
        for (int i = 0, j = 0; i < line.length(); i++)
        {
            if(isdigit(line[i]))
                seeds1[j] = seeds1[j]*10 + (line[i] - '0');
            else{
                j++;
                seeds1.resize(j+1);
                found_index.resize(j+1);
            }
        }
    }
    vector<uint> seeds(0);
    uint k = 0;
    for (int i = 0; i < seeds1.size()/2; i++)
    {
        seeds.resize(seeds.size() + seeds1[i*2+1]);
        for (int j = 0; j < seeds1[i*2+1]; j++)
        {
            seeds[k] = seeds1[i*2]+j;
            k++;
        }
    }
    

    int state = -1, before_state = 0;
    
    while(getline(f, line)){
        uint dest=0, source=0, range=0;
        if(isdigit(line[0])){
            if(before_state != state) {
                fill(found_index.begin(), found_index.end(), false); //cout << "Reset found index" << '\n';
            }
            //get destination, source and range
            for (int i = 0, j = 0; i < line.length(); i++)
            {
                if(isdigit(line[i]))
                    if(j==0)
                        dest = dest*10 + (line[i] - '0');
                    else if(j==1)
                        source = source*10 + (line[i] - '0');
                    else
                        range = range*10 + (line[i] - '0');
                else{
                    j++;
                }
            }

            //find seed in range
            for (int i = 0; i < seeds.size(); i++)
            {
                if(seeds[i] >= source && seeds[i] < source+range && !found_index[i]) {
                    seeds[i] = dest + seeds[i]-source;
                    found_index[i] = true;
                }
            }
            before_state = state;
        }
        else if(!line.empty()) state++;
    }
    //cout << seed << " - " << seeds << '\n';
    //cout << seeds[0] << '\n';
    for(uint seed : seeds){
        if(seed < lowest) lowest = seed;
    }
    return lowest;
}

int main(){
    uint p = part2();
    cout << p << '\n';
    
    return 0;
}