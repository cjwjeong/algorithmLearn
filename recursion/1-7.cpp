#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> Set;

void printSet(Set &s){
    cout << "{";
    for(int i=0; i<s.size(); i++){
        cout << s.at(i);
        if(i != s.size() - 1){
            cout << ", ";
        }
    }
    cout << "}";
}
void powerSet(Set P, Set S){
    if(S.empty()){
        printSet(P);
    }
    else{
        char t = S.front();
        S.erase(S.begin());
        powerSet(P, S);
        P.insert(P.begin(), t);
        powerSet(P, S);
    }
}
int main()
{
    Set P = {};
    Set S = {'a', 'b', 'c', 'd'};
    
    powerSet(P, S);

    return 0;
}