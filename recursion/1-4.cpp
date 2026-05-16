#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> coord;

bool findpath(int x, int y, int (&maze)[8][8], const int N = 8);
int main(){
    const int N = 8;
    int x = 0;
    int y = 0;
    
    // 0: 통로, 1: 벽, 2: 지나간 길, 3: 출구
    int maze[N][N] = {
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 1, 1, 0, 1, 1, 0, 1},
        {0, 1, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0, 0, 0, 3}
    };
    
    cout << "과연" << endl;
    cout << static_cast<int>(findpath(x, y, maze)) << endl;
    
    return 0;
}
bool findpath(int x, int y, int (&maze)[8][8], const int N){
    
    if (x < 0 || y < 0 || x >= N || y >= N){
        return false;
    }
    
    if (maze[x][y] == 3){
        return true;
    }
    
    maze[x][y] = 2;
    
    vector<coord> neighbouringCells = {
        {x-1, y},
        {x, y-1},
        {x+1, y},
        {x, y+1},
    };
    
    for (coord c : neighbouringCells){
        if (maze[c.first][c.second] != 1 && maze[c.first][c.second] != 2){
            if (findpath(c.first, c.second, maze)){
                return true;
            }
        }
    }
    
    return false;
}

