#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const string CARDS = "AKQJT98765432";

struct game{
    string hand;
    int win_amount;
};

vector<vector<game>> games(7);
int total_games = 0;

void parse(){
    ifstream f("input.txt");
    string line;

    while(getline(f, line)){
        string cards = "";
        int win_amount = 0;
        bool forwin = false;
        vector<int> prio(5);
        vector<int> occurences(CARDS.length());
        int type = 0;
        for (int i = 0; i < line.length(); i++)
        {
            if(forwin) {win_amount = win_amount*10; win_amount += (line[i] - '0');}
            //A, K, Q, J, T, 9, 8, 7, 6, 5, 4, 3, 2
            if(line[i] != ' ' && !forwin) {
                prio[i] = CARDS.length() - CARDS.find(line[i]);
                occurences[CARDS.find(line[i])] += 1;
                cards += line[i];
            } else {
                forwin = true;
            }
        }
        sort(occurences.begin(), occurences.end(), greater<int>());
        if(occurences[0] == 5)                            type = 6; //five of a kind
        else if(occurences[0] == 4)                       type = 5; //four of a kind
        else if(occurences[0] == 3 && occurences[1] == 2) type = 4; //full house
        else if(occurences[0] == 3)                       type = 3; //three of a kind
        else if(occurences[0] == 2 && occurences[1] == 2) type = 2; //two pairs
        else if(occurences[0] == 2)                       type = 1; //one pair

        //cout << "cards: " << cards << '\n' << "win points: " << win_amount << '\n' << "priority: " << prio[0] << " type: " << type << '\n';
        games[type].push_back({cards, win_amount});
        total_games++;
        
        //cout << "\n\n";
        
    }
}

bool game_sort(const game& a, const game& b){
    for (int i = 0; i < 5; i++)
    {
        if(CARDS.find(a.hand[i]) > CARDS.find(b.hand[i])) return true;
        else if(CARDS.find(a.hand[i]) < CARDS.find(b.hand[i])) return false;
    }
    return false;
}

long long part1(){
    long long sum = 0;
    int diff = 0;
    cout << total_games << '\n';
    for (int type = 0; type < games.size(); type++)
    {
        sort(games[type].begin(), games[type].end(), game_sort);
        for (int j = 0; j < games[type].size(); j++)
        {
            int rank = diff + j + 1;
            cout << type << "  " << games[type][j].hand << " rank: " << rank << '\n';
            sum += games[type][j].win_amount * rank;
        }
        diff += games[type].size();
    }
    
    return sum;
}



int main(){
    parse();
    long long p = part1();
    cout << p << '\n';
    
    return 0;
}