#include <iostream>

using namespace std;

void output_solution(int input){
  cout << "TERM " << input << " IS ";
  int l = 0;
  while (input > 0){
    l++;
    input -= l;
  }
  int numerator;
  if (input < 0){
    numerator = input + l;
  }
  else{
    numerator = l;
  }
  int denominator = l + 1 - numerator;
  if (l % 2 == 0){ 
    cout << numerator << "/" << denominator << endl;
  }
  else{
    cout << denominator << "/" << numerator << endl;
  }
}

int main(){
  int input;
  while (cin >> input){
    output_solution(input);
  }
}
