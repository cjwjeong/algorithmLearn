#include <iostream>
using namespace std;

int gcd(int m, int n){
  if(m < n){
    int tmp = m;
    m = n;
    n = tmp;
  }
  if(m%n == 0){
    return n;
  }
  return gcd(n, m%n);
}

