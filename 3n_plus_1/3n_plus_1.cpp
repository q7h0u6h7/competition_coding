#include <iostream>

using namespace std;

int cnt_cyc_len(int i){
  int cnt = 1;
  while (i > 1){
    cnt ++;
    if (i % 2){
      i = 3 * i + 1;
    }
    else{
      i /= 2;
    }
  }
  return cnt;
}

int run_alg(int a, int b){
  int cyc_len = -1;
  for (int i=min(a,b); i<=max(a,b); i++) {
    cyc_len = max(cyc_len, cnt_cyc_len(i));
  }
  return cyc_len;
}

int main(){
  int a, b;
  while (cin >> a and cin >> b) {
    cout << a <<  " " << b << " " << run_alg(a,b) << endl;
  }
  return 0;
}
