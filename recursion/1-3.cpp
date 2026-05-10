#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findmax1(vector<int> &v, int begin, int end){
  if(begin >= end){
    return v.at(begin);
  }
  return max(v.at(begin), findmax1(v, begin+1, end));
}

int findmax2(vector<int> &v, int begin, int end){
  if(begin >= end){
    return v.at(begin);
  }
  int middle = (begin + end) / 2;
  int maxl = findmax2(v, begin, middle);
  int maxr = findmax2(v, middle+1, end);
  
  return max(maxl, maxr);
}

int main(){
  vector<int> v {1, 6, 10, 2, 5};
  
  // cout << findmax1(v, 0, v.size()-1) << endl;
  cout << findmax2(v, 0, v.size()-1) << endl;
  
  return 0;
}