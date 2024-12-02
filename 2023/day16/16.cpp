#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#define SIZE 110
//110

using namespace std;

//point {right, left, top, down, isEnergized}
struct point{
    bool r,l,t,d,e;
};

const string mirrors = "./\\-|";

void beam(int direction, int x, int y, 
          vector<string> &matrix, vector<vector<point>> &energizedMap, int &energized)
{
    //cout << "beam " << direction << '\n';
    if(x<0 || y<0 || x>=SIZE || y>=SIZE) return;
    if(energizedMap[x][y].r && direction == 0) return; //left
    if(energizedMap[x][y].d && direction == 1) return; //top
    if(energizedMap[x][y].l && direction == 2) return; //right
    if(energizedMap[x][y].t && direction == 3) return; //down
    if(energizedMap[x][y].e == 0) energized++;
    energizedMap[x][y].e = 1;
    switch(mirrors.find(matrix[x][y])){
        case 0: // .
            if(direction < 2)
                beam(direction, x - direction%2, y + (direction%2-1), matrix, energizedMap, energized);
            else
                beam(direction, x + direction%2, y - (direction%2-1), matrix, energizedMap, energized);
            break;
        case 1: // /
            if(direction == 0){
                energizedMap[x][y].r = 1;
                energizedMap[x][y].d = 1;
                beam(3, x+1, y, matrix, energizedMap, energized);
            } else if(direction == 1){
                energizedMap[x][y].r = 1;
                energizedMap[x][y].d = 1;
                beam(2, x, y+1, matrix, energizedMap, energized);
            } else if(direction == 2){
                energizedMap[x][y].l = 1;
                energizedMap[x][y].t = 1;
                beam(1, x-1, y, matrix, energizedMap, energized);
            } else if(direction == 3){
                energizedMap[x][y].l = 1;
                energizedMap[x][y].t = 1;
                beam(0, x, y-1, matrix, energizedMap, energized);
            }
            break;
            break;
        case 2: // backslash
            if(direction == 0){
                energizedMap[x][y].r = 1;
                energizedMap[x][y].t = 1;
                beam(1, x-1, y, matrix, energizedMap, energized);
            } else if(direction == 1){
                energizedMap[x][y].l = 1;
                energizedMap[x][y].d = 1;
                beam(0, x, y-1, matrix, energizedMap, energized);
            } else if(direction == 2){
                energizedMap[x][y].l = 1;
                energizedMap[x][y].d = 1;
                beam(3, x+1, y, matrix, energizedMap, energized);
            } else if(direction == 3){
                energizedMap[x][y].r = 1;
                energizedMap[x][y].t = 1;
                beam(2, x, y+1, matrix, energizedMap, energized);
            }
            break;
        case 3: // -
            if(direction == 1 || direction == 3){
                energizedMap[x][y].r = 1;
                energizedMap[x][y].l = 1;
                energizedMap[x][y].t = 1;
                energizedMap[x][y].d = 1;
                beam(2, x, y + 1, matrix, energizedMap, energized);
                beam(0, x, y - 1, matrix, energizedMap, energized);
            }
            else if(direction == 0){
                energizedMap[x][y].d = 1;
                energizedMap[x][y].t = 1;
                beam(0, x, y - 1, matrix, energizedMap, energized);
            }else{
                energizedMap[x][y].d = 1;
                energizedMap[x][y].t = 1;
                beam(2, x, y + 1, matrix, energizedMap, energized);
            }
            break;
        case 4: // |
            if(direction == 0 || direction == 2){
                energizedMap[x][y].r = 1;
                energizedMap[x][y].l = 1;
                energizedMap[x][y].t = 1;
                energizedMap[x][y].d = 1;
                beam(3, x + 1, y, matrix, energizedMap, energized);
                beam(1, x - 1, y, matrix, energizedMap, energized);
            }
            else if(direction == 1){
                energizedMap[x][y].d = 1;
                energizedMap[x][y].t = 1;
                beam(1, x - 1, y, matrix, energizedMap, energized);
            }else{
                energizedMap[x][y].d = 1;
                energizedMap[x][y].t = 1;
                beam(3, x + 1, y, matrix, energizedMap, energized);
            }
            break;
        default:
            break;
    }
}

int part1(){
    int energized = 0;
    ifstream f("input.txt");
    string line;
    vector<string> matrix;
    vector<vector<point>> energizedMap(SIZE, vector<point>(SIZE));
    
    while(getline(f, line)){
        matrix.push_back(line);
    }
    line.clear();
    f.close();

    
    beam(2, 0, 0, matrix, energizedMap, energized);
    //orginal 18.9 ms ±   7.1 ms    [User: 3.5 ms, System: 6.6 ms]
    return energized;
}

int part2(){
    int energized = 0;
    ifstream f("input.txt");
    string line;
    vector<string> matrix;
    vector<vector<point>> energizedMap(SIZE, vector<point>(SIZE));
    vector<vector<point>> emptyMap(SIZE, vector<point>(SIZE));
    
    while(getline(f, line)){
        matrix.push_back(line);
    }
    line.clear();
    f.close();
    int maxEnergized = 0;
    
    for (int k = 0; k < SIZE; k++)
    {
        beam(2, k, 0, matrix, energizedMap, energized);
        if(energized>maxEnergized) maxEnergized = energized;
        energized = 0;
        energizedMap = emptyMap;
    }
    for (int k = 0; k < SIZE; k++)
    {
        beam(3, 0, k, matrix, energizedMap, energized);
        if(energized>maxEnergized) maxEnergized = energized;
        energized = 0;
        energizedMap = emptyMap;
    }
    for (int k = 0; k < SIZE; k++)
    {
        beam(0, k, SIZE-1, matrix, energizedMap, energized);
        if(energized>maxEnergized) maxEnergized = energized;
        energized = 0;
        energizedMap = emptyMap;
    }
    for (int k = 0; k < SIZE; k++)
    {
        beam(1, SIZE-1, k, matrix, energizedMap, energized);
        if(energized>maxEnergized) maxEnergized = energized;
        energized = 0;
        energizedMap = emptyMap;
    }

    return maxEnergized;
}

int main(){
    int p = part2();
    cout << p << '\n';
    
    return 0;
}