#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  string code;
  while (cin){
    cin >> code;
    if (code.compare("#") == 0){
      break;
    }
    if (next_permutation(code.begin(), code.end()) == 1){
      cout << code << endl;
    }
    else{
      cout << "No Successor" << endl;
    }
  }
}
