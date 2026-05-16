// n-queens 문제
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
vector<int> cols;
vector<vector<int>> correctCols;

bool promising(int level){
    if(level == 0){
        return true;
    }
    
    for(int i = 1; i < level; i++){
        if(cols[i] == cols[level]){
            return false;
        }
        if(abs(cols[i] - cols[level]) == abs(i - level)){
            return false;
        }
    }
    return true;
}
void nQueen(int level){
    if(!promising(level)){
        return;
    }
    else if(level == N){
        correctCols.push_back(cols);
    }
    else{
        for(int i=1; i<=N; i++){
            cols[level+1] = i;
            nQueen(level+1);
        }
    }
    
}
int main(){
    cin >> N;

    cols.resize(N + 1);

    nQueen(0);
    
    sort(correctCols.begin(), correctCols.end());
    
    for (int i=0; i<3; i++){
        for (int j=1; j < correctCols.at(i).size(); j++){
            cout << correctCols.at(i).at(j);
            cout << " ";
        }
        
        cout << endl;
    }
    

    cout << correctCols.size() << endl;
    
}