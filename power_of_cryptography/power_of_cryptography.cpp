#include <iostream>
#include <sstream>
#include <cmath>
#include <typeinfo>
#include <limits>

using namespace std;

int string_to_int(string s){
  int i;
  stringstream ss;
  ss << s;
  ss >> i;
  return i;
}

string int_to_string(int i){
  string s;
  stringstream ss;
  ss << i;
  ss >> s;
  return s;
}

int do_compare(string p, int k){
  string str_k = int_to_string(k);
  if (p.size() > str_k.size()){
    return 1;
  }
  if (p.size() < str_k.size()){
    return -1;
  }
  return p.compare(str_k);
}

int get_nth_root(string p, int n, int min_k=1, int max_k=1000000000){
    //cout << n  << " " << p << " " << do_compare(p, 20) << endl;  
//     stringstream ss;
//     ss << n;
//     ss >> str_n;
//     cout << "n: " << str_n << " " << str_n.size() << endl;
//     cout << "p: " << p << " " << p.size() << endl;
//   double possible_k = floor( (max_k - min_k) / 2) ;
//   stringstream ss;
//   cout << possible_k << " " << n << endl;
//   possible_k = pow(possible_k, n);
//   cout << ss << endl;
//   //n = do_compare(p, 26);
  
//   //cout << "do_compare: " << n << endl;


//  cout << pow(p, 1/n) << endl;

}

int main(){
//   //long long int n, p;
//   int n;
//   string p, str_n;

  double d;
  d = pow(1234.0, 7);
  cout.precision(21);
  cout << typeid(pow(1234.0, 7)).name() << " " << d <<  endl;

  double d_int = 4.35718618402138200474e+21;
  cout << "d_int: " << d_int << endl;
  if (d == d_int){
    cout << "uuuuuuu" << endl;
  }
  //d_int = 435718618402138200474;

  cout << "The maximum value for type float is:  "
       << numeric_limits<float>::max( )
       << endl;
  cout << "The maximum value for type double is:  "
       << numeric_limits<double>::max( )
       << endl;
  cout << "The maximum value for type float is:  "
       << numeric_limits<int>::max( )
       << endl;
  cout << "The maximum value for type short int is:  "
       << numeric_limits<short int>::max( )
       << endl;
  if (4357186184021382204544 < numeric_limits<double>::max( )){
    cout << "wow: " << endl;
  }


//   while (cin >> n >> p){
//     cout << get_nth_root(p, n) << endl;
//   }
}
