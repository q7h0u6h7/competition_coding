#include <iostream>

using namespace std;

int solve(int num){
  int num_matches = 0;
  while (num >= 1000){
    num -= 1000;
    num_matches += 4;
    //cout << "M";
  }
  if (num >= 900){
    num -= 900;
    num_matches += 6;
    //cout << "CM";
  }
  if (num >= 500){
    num -= 500;
    num_matches += 3;
    //cout << "D";
  }
  if (num >= 400){
    num -= 400;
    num_matches += 5;
    //cout << "CD";
  }
  while(num >= 100){
    num -= 100;
    num_matches += 2;
    //cout << "C";
  }
  if (num >= 90){
    num -= 90;
    num_matches += 4;
    //cout << "XC";
  }
  if (num >= 50){
    num -= 50;
    num_matches += 2;
    //cout << "L";
  }
  if (num >= 40){
    num -= 40;
    num_matches += 4;
    //cout << "XL";
  }
  while (num >= 10){
    num -= 10;
    num_matches += 2;
    //cout << "X";
  }
  if (num == 9){
    num_matches += 3;
    //cout << "IX";
    return num_matches;
  }
  if (num >= 5){
    num -= 5;
    num_matches += 2;
    //cout << "V";
  }
  if (num == 4){
    num_matches += 3;
    //cout << "IV";
    return num_matches;
  }
  while (num >0){
    num_matches += 1;
    num -= 1;
    //cout << "I";
  }
  //cout << " ";
  return num_matches;
}

int main(){
  int i;
  while (cin >> i){
    cout << solve(i) << endl;
  }
}
