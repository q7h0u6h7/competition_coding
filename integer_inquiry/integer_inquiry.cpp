#include <iostream>
#include <list>
#include <sstream>
#include <string>; 

using namespace std;

int str_2_int(string str){
  istringstream tmp(str);
  int out;
  tmp >> out;
  return out;
}

string int_2_string(int i){
  stringstream tmp;
  tmp << i;
  return tmp.str();
  
}

void solve(list<string> longints, int max_size){
  int carry = 0;
  int digit;
  string carry_str;
  list<int> result;
  
  for (int i=0;
       i < max_size;
       ++i){
    for (list<string>::iterator it = longints.begin();
	 it != longints.end();
	 ++it){
      if (i >= (*it).size()){
	  continue;
	}
      digit = ((*it)[i] - '0');
      //cout << "D: " << digit << endl;
      carry += digit;       
    }
    carry_str = int_2_string(carry);
    //cout << "S: " << carry_str << endl;
    digit = carry_str[carry_str.size()-1] - '0';
    //cout << "C: " << digit << endl;
    result.push_front(digit);
    //cout << "L: " << result.front() << endl;
    carry = str_2_int(carry_str);
    carry = (carry / 10);
  }
  if (carry){
    result.push_front(carry);
  }
  for (list<int>::iterator it = result.begin();
       it != result.end();
       ++it){
    cout << *it;
  }
}

int main(){
  list<string> longints;
  string lngint;
  string rlngint;
  int max_size = 0;
  while (cin >> lngint){
    rlngint = string (lngint.rbegin(), lngint.rend() );
    longints.push_back(rlngint);
    if (lngint.size() > max_size){
      max_size = lngint.size();
    }
  }
  solve(longints, max_size);
  cout << endl;
}
