#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int time[] = {52, 94, 75, 94};
int dist[] = {426, 1374, 1279, 1216};

//int time[4];
//int dist[4];

void parse(){
    bool second_line = false;
    ifstream f("inputx.txt");
    string line;
    
    while(getline(f, line)){
        int j = 0;
        for (int i = 0; i < line.length(); i++)
        {
            if(!second_line){
                if(isdigit(line[i]))
                    time[j] = time[j] + (line[i] - '0');
                else if(isdigit(line[i-1]) && !isdigit(line[i]))
                    j++;
            } else {
                if(isdigit(line[i]))
                    dist[j] = dist[j] + (line[i] - '0');
                else if(isdigit(line[i-1]) && !isdigit(line[i]))
                    j++;
            }
        }
        second_line = true;
    }
    cout << time[1];
}

int part1(){
    int curr_ways = 0;
    int ways = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < time[i]; j++)
        {
            if((time[i] - j)*j > dist[i]) curr_ways++;
        }
        ways *= curr_ways;
        curr_ways = 0;
    }
    return ways;
}

int part2(){
    int ways = 0;
    int b = 52947594;
    long long c = 426137412791216;
    //int b = 71530;
    //int c = 940200;

    //f x(time - x) - distance > 0
    //f -x^2 + bx - c > 0
    //delta b^2 - 4*c
    long long delta = pow(b, 2) - 4 * c;
    int x1 = (-b - sqrt(delta)) / 2;
    int x2 = (-b + sqrt(delta)) / 2;
    ways = abs(x2-x1);
    return ways;
}

int shitty_part2(){
    int ways = 0;
    for (long long j = 0; j < 52947594; j++)
    {
        if((52947594 - j)*j > 426137412791216) ways++;
    }
    return ways;
}

int main(){
    int p = part2();
    cout << p << '\n';
    cout << ((p == 33149631) ? "git" : "zle");
    
    return 0;
}