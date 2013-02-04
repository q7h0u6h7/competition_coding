#include <iostream>
#include <sstream>
#include <stdio.h>

using namespace std;

int string_to_int(string str){
  stringstream s(str);
  int r;
  s >> r;
  return r;
}

float get_hour(int h, int m){
  return (h % 12) * 30 + (m/60.0) * 30;
}

float get_minute(int m){
  return ((m/60.0) * 360.0);
} 

float solve(string time){
  float r, hour, minute;
  string sh, sm;
  int h, m;
  stringstream st(time);
  getline(st, sh, ':');
  getline(st, sm, ':');
  h = string_to_int(sh);
  m = string_to_int(sm);
  hour = get_hour(h, m);
  minute = get_minute(m);
  r = hour - minute;
  if (r < 0){
    r *= -1;
  }
  if (r > 180){
    r = 360 - r;
  }
  return r;
}

int main(){
  string time;
  float result;
  while (cin >> time and time != "0:00"){
    result = solve(time);
    printf("%.3f", result);
    cout << endl;
  }
}
