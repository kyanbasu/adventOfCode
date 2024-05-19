#include <iostream>
#include <fstream>
#include <vector>
//cmath not really required, used just once in part 1 for power function
#include <cmath>

using namespace std;

const string input = "input.txt";
//check if example input and tweak constants
const int WIN_NUM = (input == "inputx.txt") ? 5 : 10;
const int GUESSES = (input == "inputx.txt") ? 8 : 25;

const int card_len = (input == "inputx.txt") ? 1 : 3;

unsigned int part1(){
    ifstream f(input);
    string line;

    unsigned int sum = 0;
    while(getline(f, line)){
        line = line.substr(7+card_len, line.length()-(7+card_len));
        line = line.substr(0, WIN_NUM*3) + line.substr(WIN_NUM*3+2, WIN_NUM*3+3 + GUESSES*3);
        string winning_numbers = "";
        int guessed = -1;
        for (int i = 0; i < WIN_NUM + GUESSES; i++)
        {
            string check = line.substr(i*3, 3);
            check[2] = '.';
            if(i < WIN_NUM) winning_numbers += check;
            else{
                if(winning_numbers.find(check) != string::npos) guessed++;
            }
            cout << check;
            if(i+1 == WIN_NUM + GUESSES) cout << '\n' << winning_numbers << '\n';
        }
        sum += pow(2, guessed);
    }
    return sum;
}

unsigned int part2(){
    vector<int> total_cards;
    if(card_len == 1){
        total_cards.resize(6);
        for (int i = 0; i < 6; i++)
        {
            total_cards[i] = 1;
        }
    }else{
        total_cards.resize(199);
        for (int i = 0; i < 199; i++)
        {
            total_cards[i] = 1;
        }
    }
    ifstream f(input);
    string line;

    unsigned int sum = 0;
    int card_num = 0;
    while(getline(f, line)){
        line = line.substr(7+card_len, line.length()-(7+card_len));
        line = line.substr(0, WIN_NUM*3) + line.substr(WIN_NUM*3+2, WIN_NUM*3+3 + GUESSES*3);
        string winning_numbers = "";
        int guessed = 0;
        for (int i = 0; i < WIN_NUM + GUESSES; i++)
        {
            string check = line.substr(i*3, 3);
            check[2] = '.';
            if(i < WIN_NUM) winning_numbers += check;
            else{
                if(winning_numbers.find(check) != string::npos) guessed++;
            }
            //cout << check;
            //if(i+1 == WIN_NUM + GUESSES) cout << '\n' << winning_numbers << '\n';
        }
        for (int i = 0; i < guessed; i++)
        {
            total_cards[card_num+i+1] += 1*total_cards[card_num];
        }
        
        card_num++;
    }
    for (int &i : total_cards)
    {
        cout << i << ", ";
        sum += i;
    }

    return sum;
}

int main(){
    //part1
    //unsigned int p1 = part1();
    //cout << p1 << '\n';
    //cout << (p1 > 956 && p1 < 21847);

    //part2
    unsigned int p2 = part2();
    cout << '\n' << p2 << '\n';
    
    return 0;
}
