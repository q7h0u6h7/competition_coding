#include <iostream>
#include <cmath>

using namespace std;

int solve(int b, int p, int m){
  float new_b = b % m;
  int new_p = p % (m-1);
  
  //cout << "new_b: " << new_b << endl;
  //cout << "new_p: " << new_p << endl;

  if (new_p > 1){
    return solve(new_b * new_b, new_p-1, m);
  }
  else{
    long double f = pow(new_b, new_p);
    cout << "f: " << f << endl;
    return f;
  }
}


int main(){
  int b, p, m, r;
  while (cin >> b and cin >> p and cin >> m){
    //cout << "b: " << b << endl;
    //cout << "p: " << p << endl;
    //cout << "m: " << m << endl;
    r = solve(b, p, m);
    cout << r << endl;
  }
}
