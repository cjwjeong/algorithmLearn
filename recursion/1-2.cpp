#include <iostream>
#include <string>

using namespace std;

void printStr(string str){
  if (str.size() == 0){
    return ;
  }
  std::cout << str.at(0);
  printStr(str.substr(1));
}

void printStrReverse(string str){
  if (str.size() == 0){
    return ;
  }
    printStrReverse(str.substr(1));
    std::cout << str.at(0);
}